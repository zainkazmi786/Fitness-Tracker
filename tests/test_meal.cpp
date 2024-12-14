#include "../include/meal.h"
#include <iostream>
#include <cassert>
using namespace std;

void testAddMeal(){
    MealPlan mealPlan;
    Meal meal1("Chicken Salad", 300, 25.0, 10.0, 5.0);
    Meal meal2("Pasta", 500, 15.0, 60.0, 10.0);

    mealPlan.addMeal(meal1);
    mealPlan.addMeal(meal2);


    assert(mealPlan.getTotalCalories() == 800);
    assert(mealPlan.getTotalProtein() == 40.0);
    assert(mealPlan.getTotalCarbs() == 70.0);
    assert(mealPlan.getTotalFats() == 15.0);

    cout << "Test add meal passed.\n";
}

void testRemoveMeal() {
    MealPlan mealPlan;
    Meal meal1("Chicken Salad", 300, 25.0, 10.0, 5.0);
    Meal meal2("Pasta", 500, 15.0, 60.0, 10.0);

    mealPlan.addMeal(meal1);
    mealPlan.addMeal(meal2);
    mealPlan.removeMeal("Pasta");

    assert(mealPlan.getTotalCalories() == 300);
    assert(mealPlan.getTotalProtein() == 25.0);
    assert(mealPlan.getTotalCarbs() == 10.0);
    assert(mealPlan.getTotalFats() == 5.0);

    cout << "testRemoveMeal passed.\n";
}

void testDisplayMealPlan() {
    MealPlan mealPlan;
    Meal meal1("Chicken Salad", 300, 25.0, 10.0, 5.0);

    mealPlan.addMeal(meal1);

    cout << "Meal Plan Display Test:\n";
    mealPlan.displayMealPlan();

    cout << "testDisplayMealPlan passed.\n";
}
void testSaveAndLoad() {
    MealPlan mealPlan;
    Meal meal1("Chicken Salad", 300, 25.0, 10.0, 5.0);
    Meal meal2("Pasta", 500, 15.0, 60.0, 10.0);

    mealPlan.addMeal(meal1);
    mealPlan.addMeal(meal2);

    mealPlan.saveToFile("./data/meal_data.txt");

    MealPlan loadedMealPlan;
    loadedMealPlan.loadFromFile("./data/meal_data.txt");

    assert(loadedMealPlan.getTotalCalories() == mealPlan.getTotalCalories());
    assert(loadedMealPlan.getTotalProtein() == mealPlan.getTotalProtein());
    assert(loadedMealPlan.getTotalCarbs() == mealPlan.getTotalCarbs());
    assert(loadedMealPlan.getTotalFats() == mealPlan.getTotalFats());

    cout << "testSaveAndLoad passed.\n";
}


int main() {
    
    testAddMeal();
    testRemoveMeal();
    testDisplayMealPlan();
    testSaveAndLoad();
    cout << "All tests passed!\n";
    return 0;
}
