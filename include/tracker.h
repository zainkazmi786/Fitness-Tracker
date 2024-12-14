#ifndef TRACKER_H
#define TRACKER_H

#include <unordered_map>
#include <list>
#include <string>
#include "user.h"

using namespace std;

// Exercise class definition
class Exercise {
public:
    string name;
    string category;
    int duration;          
    int baseCaloriesBurned; // Base calories burned for 70 kg
    int difficulty;
    

    Exercise();
    Exercise(string name, string category, int duration, int baseCaloriesBurned, int difficulty);
};

class Exercises {
public:
    unordered_map<string, Exercise> exercises;

    void addExercise(const Exercise& exercise);

    list<pair<string, int>> recommendForUser(const User& user, int timeSpan);
};

#endif 
