#pragma once
#include "Person.h"
#include <vector>

class Course; // Forward declaration

class Student : public Person {
private:
    std::vector<Course*> enrolledCourses;
public:
    Student(std::string name, int age);
    void enrollCourse(Course* course);
    void displayCourses() const;
};
