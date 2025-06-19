#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course; // forward declaration

class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    string getName() const { return name; }
};

class Student : public Person {
private:
    vector<Course*> enrolledCourses;
public:
    Student(string name, int age) : Person(name, age) {}

    void enrollCourse(Course* course);
    void displayCourses() const;
};

class Professor : public Person {
private:
    vector<Course*> assignedCourses;
public:
    Professor(string name, int age) : Person(name, age) {}

    void assignCourse(Course* course);
    void displayAssignedCourses() const;
};

class Course {
private:
    string courseName;
    vector<Student*> enrolledStudents;
public:
    Course(string name) : courseName(name) {}

    void addStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    string getCourseName() const { return courseName; }

    void displayEnrolledStudents() const {
        cout << "- " << courseName << endl;
        cout << "  Enrolled Students:" << endl;
        for (auto student : enrolledStudents) {
            cout << "  - " << student->getName() << endl;
        }
    }
};

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
    course->addStudent(this);
}

void Student::displayCourses() const {
    cout << "Student: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Enrolled Courses:" << endl;
    for (auto course : enrolledCourses) {
        cout << "- " << course->getCourseName() << endl;
    }
    cout << endl;
}

void Professor::assignCourse(Course* course) {
    assignedCourses.push_back(course);
}

void Professor::displayAssignedCourses() const {
    cout << "Professor: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Assigned Courses:" << endl;
    for (auto course : assignedCourses) {
        cout << "- " << course->getCourseName() << endl;
    }
    cout << endl;
}

class Department {
private:
    string departmentName;
    vector<Professor*> professors;
    vector<Course*> courses;
public:
    Department(string name) : departmentName(name) {}

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void addCourse(Course* c) {
        courses.push_back(c);
    }

    void displayProfessorsAndCourses() const {
        cout << "Department: " << departmentName << endl;
        cout << "Professors:" << endl;
        for (auto prof : professors) {
            cout << "- " << prof->getName() << endl;
            cout << "  Assigned Courses:" << endl;
            for (auto course : courses) {
                if (find(prof->assignedCourses.begin(), prof->assignedCourses.end(), course) != prof->assignedCourses.end()) {
                    cout << "  - " << course->getCourseName() << endl;
                }
            }
        }
        cout << "Courses:" << endl;
        for (auto course : courses) {
            course->displayEnrolledStudents();
        }
    }
};

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
