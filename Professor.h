#pragma once
#include "Person.h"
#include <vector>

class Course;

class Professor : public Person {
private:
    std::vector<Course*> assignedCourses;
public:
    Professor(std::string name, int age);
    void assignCourse(Course* course);
    void displayAssignedCourses() const;
    const std::vector<Course*>& getCourses() const;
};