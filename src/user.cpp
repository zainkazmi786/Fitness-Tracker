#include "../include/user.h"
#include <iostream>
using namespace std;


User::User(string name, int age, double weight, double height)
    : name(name), age(age), weight(weight), height(height) {}


void User::displayProfile() {
    cout << "Name: " << name << "\nAge: " << age
              << "\nWeight: " << weight << " kg\nHeight: " << height << " m\n";
}


void User::updateProfile(double newWeight, double newHeight) {
    weight = newWeight;
    height = newHeight;
    cout << "Profile updated!\n";
}
