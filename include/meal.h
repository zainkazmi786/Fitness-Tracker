#ifndef MEAL_H
#define MEAL_H

#include <string>
#include <list>
using namespace std;

class Meal {
private:
    string name;
    int calories;
    double protein;
    double carbs;
    double fats;

public:
    Meal(const string& name, int calories, double protein, double carbs, double fats);
    string getName() const;
    int getCalories() const;
    double getProtein() const;
    double getCarbs() const;
    double getFats() const;

    void setName(const string& name);
    void setCalories(int calories);
    void setProtein(double protein);
    void setCarbs(double carbs);
    void setFats(double fats);
    void displayMeal() const;
};

// Class to manage a meal plan (a collection of meals)
class MealPlan {
private:
    list<Meal> meals; // List of meals in the plan

public:
    // Add a meal to the plan
    void addMeal(const Meal& meal);

    // Remove a meal from the plan by name
    void removeMeal(const string& mealName);

    // Calculate total nutritional values for the plan
    int getTotalCalories() const;
    double getTotalProtein() const;
    double getTotalCarbs() const;
    double getTotalFats() const;
    void saveToFile(const std::string& filename) const;

    // Load the meal plan from a file
    void loadFromFile(const std::string& filename);
    
    // Display the entire meal plan
    void displayMealPlan() const;

    // Function to recommend meals based on user weight
    list<Meal> recommendMealsForUser(double userWeight);
};

#endif
