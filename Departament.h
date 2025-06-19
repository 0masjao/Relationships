#pragma once
#include <string>
#include <vector>
#include "Professor.h"
#include "Course.h"

class Department {
private:
    std::string departmentName;
    std::vector<Professor*> professors;
    std::vector<Course*> courses;
public:
    Department(std::string name);
    void addProfessor(Professor* p);
    void addCourse(Course* c);
    void displayProfessorsAndCourses() const;
};