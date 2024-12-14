#include "../include/tracker.h"
#include "../include/utils.h"
#include <list>
using namespace std;

// Exercise class implementation
Exercise::Exercise(string name, string category, int duration, int baseCaloriesBurned, int difficulty)
    : name(name), category(category), duration(duration), baseCaloriesBurned(baseCaloriesBurned), difficulty(difficulty) {}

Exercise::Exercise()
    : name(""), category(""), duration(0), baseCaloriesBurned(0), difficulty(0) {}

// Adds an exercise to the Exercises
void Exercises::addExercise(const Exercise& exercise) {
    exercises[exercise.name] = exercise;
}

// Recommends exercises based on user's weight and time span
list<pair<string, int>> Exercises::recommendForUser(const User& user, int timeSpan) {
    list<pair<string, int>> recommendations;

    for (const auto& exercisePair : exercises) {
        const Exercise& exercise = exercisePair.second; // Access the Exercise object

        // Adjust recommendation logic based on user weight and difficulty level
        if (user.weight > 65) {
            // For heavier users, prioritize exercises with higher difficulty
            if (exercise.difficulty >= 3) { // Difficulty levels: 1 = Easy, 2 = Medium, 3+ = Hard
                int totalCalories = (exercise.baseCaloriesBurned * timeSpan) / exercise.duration;
                recommendations.push_back({exercise.name, totalCalories});
            }
        } else {
            // For lighter users, recommend all exercises
            int totalCalories = (exercise.baseCaloriesBurned * timeSpan) / exercise.duration;
            recommendations.push_back({exercise.name, totalCalories});
        }
    }

    // Sort recommendations by calories burned (descending)
    bubbleSort(recommendations);


    return recommendations;
}


