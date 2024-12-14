#include <iostream>
#include "../include/meal.h"
#include "../include/tracker.h"
#include "../include/user.h"
using namespace std;

int main() {
    // Create two users
    User user1("John Doe", 25, 50, 1800); 
    User user2("Jane Smith", 30, 85, 2200); // Name: Jane Smith, Weight: 85kg

    // Create a exercises and add multiple exercises
    Exercises exercises;
    exercises.addExercise(Exercise("Push Up", "Strength", 7, 10, 3));
    exercises.addExercise(Exercise("Jumping Jacks", "Cardio", 10, 5, 1));
    exercises.addExercise(Exercise("Burpees", "Cardio", 15, 8, 5));
    exercises.addExercise(Exercise("Plank", "Core", 5, 5, 2));
    exercises.addExercise(Exercise("Squats", "Strength", 8, 10, 4));
    exercises.addExercise(Exercise("Running", "Cardio", 12, 20, 2));
    exercises.addExercise(Exercise("Deadlifts", "Strength", 20, 15, 5));
    exercises.addExercise(Exercise("Bicycling", "Cardio", 15, 30, 3));

    // User specifies a time span
    int timeSpan = 20; // Time span in minutes

    // Get exercise recommendations for user1
    list<pair<string, int>> exerciseRecommendations1 = exercises.recommendForUser(user1, timeSpan);

    // Get exercise recommendations for user2
    list<pair<string, int>> exerciseRecommendations2 = exercises.recommendForUser(user2, timeSpan);

    // Display exercise recommendations for user1
    cout << "Recommendations for " << user1.name << " (Weight: " << user1.weight << " kg, Time: " << timeSpan << " minutes):\n";
    for (const auto& rec : exerciseRecommendations1) {
        cout << rec.first << " - Calories Burned: " << rec.second << endl;
    }

    // Display exercise recommendations for user2
    cout << "\nRecommendations for " << user2.name << " (Weight: " << user2.weight << " kg, Time: " << timeSpan << " minutes):\n";
    for (const auto& rec : exerciseRecommendations2) {
        cout << rec.first << " - Calories Burned: " << rec.second << endl;
    }

    // Create multiple meal objects
    Meal chickenSalad("Chicken Salad", 350, 25.0, 10.0, 15.0);
    Meal veggieBowl("Veggie Bowl", 300, 10.0, 50.0, 5.0);
    Meal steak("Steak", 500, 40.0, 0.0, 25.0);
    Meal fruitSmoothie("Fruit Smoothie", 200, 5.0, 40.0, 1.0);
    Meal salmon("Grilled Salmon", 450, 35.0, 0.0, 20.0);
    Meal quinoaBowl("Quinoa Bowl", 400, 15.0, 60.0, 10.0);
    Meal peanutButterToast("Peanut Butter Toast", 250, 10.0, 30.0, 12.0);

    // Create meal plan and add meals
    MealPlan mealPlan;
    mealPlan.addMeal(chickenSalad);
    mealPlan.addMeal(veggieBowl);
    mealPlan.addMeal(steak);
    mealPlan.addMeal(fruitSmoothie);
    mealPlan.addMeal(salmon);
    mealPlan.addMeal(quinoaBowl);
    mealPlan.addMeal(peanutButterToast);

    // Recommend meals based on user weight
    list<Meal> recommendedMeals1 = mealPlan.recommendMealsForUser(user1.weight);
    list<Meal> recommendedMeals2 = mealPlan.recommendMealsForUser(user2.weight);

    // Display recommended meals for user1
    cout << "\nRecommended Meals for " << user1.name << ":\n";
    for (const Meal& meal : recommendedMeals1) {
        meal.displayMeal();
    }

    // Display recommended meals for user2
    cout << "\nRecommended Meals for " << user2.name << ":\n";
    for (const Meal& meal : recommendedMeals2) {
        meal.displayMeal();
    }

    return 0;
}
