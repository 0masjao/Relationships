#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name, int age);
    virtual void displayInfo() const;
    std::string getName() const;
};
