#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    int studentID;
    string name;
    string level;
    string major;
    double gpa;
    int advisorID;

public:
    Student(int id, string n, string lvl, string mjr, double gradePointAverage, int advisor){
        studentID = id;
        name = n;
        level = lvl;
        major = mjr;
        gpa = gradePointAverage;
        advisorID = advisor;
    }
    

    // Accessor functions
    int getID() const {
        return studentID;
    }
    string getName() const { 
        return name; 
    }
    string getLevel() const { 
        return level; 
    }
    string getMajor() const { 
        return major; 
    }
    double getGPA() const { 
        return gpa; 
    }
    int getAdvisorID() const { 
        return advisorID; 
    }

    // Mutator functions
    void setAdvisorID(int newAdvisorID) { 
        advisorID = newAdvisorID; 
    }

    // Overloaded operators
    bool operator==(const Student& other) const { return studentID == other.studentID; }
    bool operator<(const Student& other) const { return studentID < other.studentID; }
    bool operator>(const Student& other) const { return studentID > other.studentID; }

    // Display student information
    void display() const {
        cout << "Student ID: " << studentID
                  << ", Name: " << name
                  << ", Level: " << level
                  << ", Major: " << major
                  << ", GPA: " << gpa
                  << ", Advisor ID: " << advisorID << std::endl;
    }
};
