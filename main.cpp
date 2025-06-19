#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Department.h"

Person::Person(std::string name, int age) : name(name), age(age) {}
void Person::displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
std::string Person::getName() const { return name; }

Student::Student(std::string name, int age) : Person(name, age) {}
void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
    course->addStudent(this);
}
void Student::displayCourses() const {
    std::cout << "Student: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Enrolled Courses:" << std::endl;
    for (auto course : enrolledCourses) {
        std::cout << "- " << course->getCourseName() << std::endl;
    }
    std::cout << std::endl;
}

Professor::Professor(std::string name, int age) : Person(name, age) {}
void Professor::assignCourse(Course* course) {
    assignedCourses.push_back(course);
}
void Professor::displayAssignedCourses() const {
    std::cout << "Professor: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Assigned Courses:" << std::endl;
    for (auto course : assignedCourses) {
        std::cout << "- " << course->getCourseName() << std::endl;
    }
    std::cout << std::endl;
}
const std::vector<Course*>& Professor::getCourses() const {
    return assignedCourses;
}

Course::Course(std::string name) : courseName(name) {}
void Course::addStudent(Student* student) {
    enrolledStudents.push_back(student);
}
std::string Course::getCourseName() const {
    return courseName;
}
void Course::displayEnrolledStudents() const {
    std::cout << "- " << courseName << std::endl;
    std::cout << "  Enrolled Students:" << std::endl;
    for (auto student : enrolledStudents) {
        std::cout << "  - " << student->getName() << std::endl;
    }
}

Department::Department(std::string name) : departmentName(name) {}
void Department::addProfessor(Professor* p) {
    professors.push_back(p);
}
void Department::addCourse(Course* c) {
    courses.push_back(c);
}
void Department::displayProfessorsAndCourses() const {
    std::cout << "Department: " << departmentName << std::endl;
    std::cout << "Professors:" << std::endl;
    for (auto prof : professors) {
        std::cout << "- " << prof->getName() << std::endl;
        std::cout << "  Assigned Courses:" << std::endl;
        for (auto course : prof->getCourses()) {
            std::cout << "  - " << course->getCourseName() << std::endl;
        }
    }
    std::cout << "Courses:" << std::endl;
    for (auto course : courses) {
        course->displayEnrolledStudents();
    }
}

int main() {
    Student john("John Doe", 20);
    Student jane("Jane Doe", 21);
    Professor smith("Dr. Smith", 45);

    Course math("Math 101");
    Course physics("Physics 101");
    Course chemistry("Chemistry 101");

    john.enrollCourse(&math);
    john.enrollCourse(&physics);
    jane.enrollCourse(&physics);

    smith.assignCourse(&math);
    smith.assignCourse(&chemistry);

    Department science("Science Department");
    science.addProfessor(&smith);
    science.addCourse(&math);
    science.addCourse(&physics);
    science.addCourse(&chemistry);

    john.displayCourses();
    smith.displayAssignedCourses();
    science.displayProfessorsAndCourses();

    return 0;
}

