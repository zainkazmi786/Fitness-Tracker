#include "../include/meal.h"
#include <iostream>
#include <fstream>
#include <sstream>
// #include <algorithm>

// Meal class implementation
Meal::Meal(const std::string& name, int calories, double protein, double fat, double carbs)
    : name(name), calories(calories), protein(protein), fats(fat), carbs(carbs) {}

string Meal::getName() const { return name; }
int Meal::getCalories() const { return calories; }
double Meal::getProtein() const { return protein; }
double Meal::getCarbs() const { return carbs; }
double Meal::getFats() const { return fats; }

void Meal::setName(const string& name) { this->name = name; }
void Meal::setCalories(int calories) { this->calories = calories; }
void Meal::setProtein(double protein) { this->protein = protein; }
void Meal::setCarbs(double carbs) { this->carbs = carbs; }
void Meal::setFats(double fats) { this->fats = fats; }

void Meal::displayMeal() const {
    std::cout << "Meal: " << name 
              << ", Calories: " << calories 
              << ", Protein: " << protein << "g, "
              << "Carbs: " << carbs << "g, "
              << "Fats: " << fats << "g\n";
}

// MealPlan class implementation
void MealPlan::addMeal(const Meal& meal) {
    meals.push_back(meal);
}

void MealPlan::removeMeal(const string& mealName) {
    meals.remove_if([&](const Meal& meal) { return meal.getName() == mealName; });
}

int MealPlan::getTotalCalories() const {
    int total = 0;
    for (const auto& meal : meals) {
        total += meal.getCalories();
    }
    return total;
}

double MealPlan::getTotalProtein() const {
    double total = 0.0;
    for (const auto& meal : meals) {
        total += meal.getProtein();
    }
    return total;
}

double MealPlan::getTotalCarbs() const {
    double total = 0.0;
    for (const auto& meal : meals) {
        total += meal.getCarbs();
    }
    return total;
}

double MealPlan::getTotalFats() const {
    double total = 0.0;
    for (const auto& meal : meals) {
        total += meal.getFats();
    }
    return total;
}

void MealPlan::displayMealPlan() const {
    std::cout << "Meal Plan:\n";
    for (const auto& meal : meals) {
        meal.displayMeal();
    }
}

list<Meal> MealPlan::recommendMealsForUser(double weight) {
    list<Meal> recommendedMeals;

    for (const auto& meal : meals) {
        if (weight < 60 && meal.getProtein() > 20) {
            recommendedMeals.push_back(meal); // High protein for low weight
        } else if (weight >= 60 && meal.getCalories() < 400) {
            recommendedMeals.push_back(meal); // Low calorie for high weight
        }
    }

    return recommendedMeals;
}
void MealPlan::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& meal : meals) {
        outFile << meal.getName() << ","
                << meal.getCalories() << ","
                << meal.getProtein() << ","
                << meal.getFats() << ","
                << meal.getCarbs() << "\n";
    }

    outFile.close();
    std::cout << "Meal plan saved to file: " << filename << std::endl;
}

void MealPlan::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    meals.clear();
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string name;
        int calories;
        double protein, fat, carbs;

        std::getline(ss, name, ',');
        ss >> calories;
        ss.ignore(1); // Ignore comma
        ss >> protein;
        ss.ignore(1); // Ignore comma
        ss >> fat;
        ss.ignore(1); // Ignore comma
        ss >> carbs;

        meals.emplace_back(name, calories, protein, fat, carbs);
    }

    inFile.close();
    std::cout << "Meal plan loaded from file: " << filename << std::endl;
}

