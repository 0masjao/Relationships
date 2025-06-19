[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/dpX8tHzC)
# C++ Class Relations Mastery Task

## Overview

This task is designed to help you master the understanding of class relationships in C++ programming. You will practice implementing and working with different types of class relationships, including **composition**, **aggregation**, **inheritance**, and **association**. By completing this task, you will gain hands-on experience in designing and implementing object-oriented systems.

---

## Learning Objectives

By the end of this task, you should be able to:
1. Understand and implement composition and aggregation in C++.
2. Use inheritance to create derived classes and override methods.
3. Differentiate between association, aggregation, and composition.
4. Write clean, modular, and reusable code using object-oriented principles.

---

## Task Description

You are tasked with designing and implementing a simple simulation of a university system. The system will consist of several classes that represent different entities in a university, such as `Student`, `Professor`, `Course`, and `Department`. Each class will have specific attributes and methods, and you will need to establish relationships between them.

### Requirements

1. **Classes to Implement**
   - `Person`: A base class representing a person in the university. It should have attributes like `name` and `age`.
   - `Student`: A derived class from `Person`. It should include additional attributes like `studentID` and a list of enrolled courses.
   - `Professor`: Another derived class from `Person`. It should include attributes like `employeeID` and a list of courses they teach.
   - `Course`: A class representing a course offered by the university. It should have attributes like `courseID`, `courseName`, and a list of enrolled students.
   - `Department`: A class representing a department in the university. It should have attributes like `departmentName` and a list of professors and courses.

2. **Relationships to Implement**
   - **Composition**: A `Course` is composed of a list of enrolled `Student` objects.
   - **Aggregation**: A `Department` aggregates `Professor` and `Course` objects.
   - **Inheritance**: Both `Student` and `Professor` inherit from the `Person` class.
   - **Association**: A `Student` is associated with multiple `Course` objects, and a `Professor` is associated with multiple `Course` objects.

3. **Methods to Implement**
   - `Person`:
     - `void displayInfo()`: Displays the name and age of the person.
   - `Student`:
     - `void enrollCourse(Course* course)`: Adds a course to the student's list of enrolled courses.
     - `void displayCourses()`: Displays all courses the student is enrolled in.
   - `Professor`:
     - `void assignCourse(Course* course)`: Assigns a course to the professor.
     - `void displayAssignedCourses()`: Displays all courses the professor teaches.
   - `Course`:
     - `void addStudent(Student* student)`: Adds a student to the course's list of enrolled students.
     - `void displayEnrolledStudents()`: Displays all students enrolled in the course.
   - `Department`:
     - `void addProfessor(Professor* professor)`: Adds a professor to the department.
     - `void addCourse(Course* course)`: Adds a course to the department.
     - `void displayProfessorsAndCourses()`: Displays all professors and their assigned courses in the department.

4. **Main Function**
   - Create instances of `Student`, `Professor`, `Course`, and `Department`.
   - Demonstrate the relationships by enrolling students in courses, assigning courses to professors, and adding professors and courses to a department.
   - Call the appropriate methods to display information about the students, professors, courses, and department.

---


## Evaluation Criteria

Your submission will be evaluated based on the following criteria:
1. **Correctness**: Does your code correctly implement the required relationships and functionality?
2. **Code Quality**: Is your code well-structured, readable, and commented appropriately?
3. **Object-Oriented Design**: Have you effectively used inheritance, composition, aggregation, and association?
4. **Functionality**: Does your program produce the expected output when run?

---

## Example Output

When you run your program, the output might look something like this:

```
Student: John Doe
Age: 20
Enrolled Courses:
- Math 101
- Physics 101

Professor: Dr. Smith
Age: 45
Assigned Courses:
- Math 101
- Chemistry 101

Department: Science Department
Professors:
- Dr. Smith
  Assigned Courses:
  - Math 101
  - Chemistry 101
Courses:
- Math 101
  Enrolled Students:
  - John Doe
- Physics 101
  Enrolled Students:
  - Jane Doe
```

---

## Additional Notes

- Feel free to add extra features or methods if you want to go beyond the basic requirements.
- If you encounter any issues or have questions, feel free to open an issue in this repository or reach out to your instructor.

Good luck, and happy coding!
