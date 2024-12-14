#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
    
public:
    string name;
    int age;
    double weight;
    double height;


    
    User(string name, int age, double weight, double height);
    
    void displayProfile();
    void updateProfile(double weight, double height);
};

#endif 
