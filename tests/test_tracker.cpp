#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Exercise {
public:
    string name;
    string category;
    int duration;
    int caloriesBurned;
    int difficulty;

    Exercise(string name, string category, int duration, int caloriesBurned, int difficulty)
        : name(name), category(category), duration(duration), caloriesBurned(caloriesBurned), difficulty(difficulty) {}

    // Default constructor
    Exercise() : name(""), category(""), duration(0), caloriesBurned(0), difficulty(0) {}
};

class Graph {
public:
    unordered_map<string, Exercise> exercises;

    vector<string> weightedRecommendation(const string& exerciseName, bool ascending) {
        vector<pair<string, int>> exercisesList;

        for (auto& pair : exercises) {
            exercisesList.push_back(make_pair(pair.first, pair.second.difficulty));  
        }

        sort(exercisesList.begin(), exercisesList.end(), [ascending](const pair<string, int>& a, const pair<string, int>& b) {
            return ascending ? a.second < b.second : a.second > b.second;
        });

        vector<string> recommendations;
        for (const auto& exercise : exercisesList) {
            recommendations.push_back(exercise.first);
        }

        return recommendations;
    }
};

int main() {
    // Create a graph object
    Graph graph;

    // Add a variety of exercises
    graph.exercises["Push Up"] = Exercise("Push Up", "Strength", 10, 100, 3);
    graph.exercises["Pull Up"] = Exercise("Pull Up", "Strength", 15, 150, 4);
    graph.exercises["Squats"] = Exercise("Squats", "Strength", 12, 120, 2);
    graph.exercises["Plank"] = Exercise("Plank", "Core", 5, 50, 1);
    graph.exercises["Burpees"] = Exercise("Burpees", "Cardio", 8, 80, 5);
    graph.exercises["Jumping Jacks"] = Exercise("Jumping Jacks", "Cardio", 6, 60, 1);
    graph.exercises["Mountain Climbers"] = Exercise("Mountain Climbers", "Cardio", 10, 90, 4);

    // Demonstrate recommendations in ascending order (easier exercises first)
    cout << "Recommendations in ascending order of difficulty:\n";
    vector<string> easyRecommendations = graph.weightedRecommendation("Push Up", true);
    for (const string& rec : easyRecommendations) {
        cout << rec << endl;
    }

    cout << "\n";

    // Demonstrate recommendations in descending order (harder exercises first)
    cout << "Recommendations in descending order of difficulty:\n";
    vector<string> hardRecommendations = graph.weightedRecommendation("Pull Up", false);
    for (const string& rec : hardRecommendations) {
        cout << rec << endl;
    }

    cout << "\n";

    // Add a use case for user-specific preferences
    cout << "User preference: Core exercises in ascending order of difficulty:\n";
    vector<string> coreExercises;
    for (const auto& pair : graph.exercises) {
        if (pair.second.category == "Cardio") {
            coreExercises.push_back(pair.first);
        }
    }
    sort(coreExercises.begin(), coreExercises.end(), [&](const string& a, const string& b) {
        return graph.exercises[a].difficulty < graph.exercises[b].difficulty;
    });
    for (const string& exercise : coreExercises) {
        cout << exercise << endl;
    }

    return 0;
}

