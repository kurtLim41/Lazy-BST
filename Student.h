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
    Student(){
        studentID = 0;
        name = "na";
        level = "na";
        major = "na";
        gpa = 0;
        advisorID = 0;
    }

    // Constructor with id
    Student(int id){
        studentID = id;
        name = "na";
        level = "na";
        major = "na";
        gpa = 0;
        advisorID = 0;

    }


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

     // Overloaded Operators

    // Equality operator
    bool operator==(const Student &other) const {
        return studentID == other.studentID;
    }

    // Less than operator
    bool operator<(const Student &other) const {
        return studentID < other.studentID;
    }

    // Greater than operator
    bool operator>(const Student &other) const {
        return studentID > other.studentID;
    }

    // Less than or equal to operator
    bool operator<=(const Student &other) const {
        return studentID <= other.studentID;
    }

    // Greater than or equal to operator
    bool operator>=(const Student &other) const {
        return studentID >= other.studentID;
    }

    // Not equal to operator 
    bool operator!=(const Student &other) const {
        return studentID != other.studentID;
    }

    // Mutator for Advisor ID
    void setAdvisor(int newAdvisor) { advisorID = newAdvisor; }


    // Display student information
    void display() const {
        cout << "Student ID: " << studentID
                  << ", Name: " << name
                  << ", Level: " << level
                  << ", Major: " << major
                  << ", GPA: " << gpa
                  << ", Advisor ID: " << advisorID << std::endl;
    }

    friend::ostream& operator<<(ostream& os, const Student& student) {
    os << "ID: " << student.studentID
       << ", Name: " << student.name
       << ", Level: " << student.level
       << ", Major: " << student.major
       << ", GPA: " << student.gpa
       << ", Advisor ID: " << student.advisorID;
    return os;
    }

    // Input operator to input Student information
    friend istream &operator>>(istream &in, Student &student) {
        cout << "Enter ID: ";
        in >> student.studentID;
        in.ignore();
        cout << "Enter name: ";
        getline(in, student.name);
        cout << "Enter level: ";
        getline(in, student.level);
        cout << "Enter major: ";
        getline(in, student.major);
        cout << "Enter GPA: ";
        in >> student.gpa;
        cout << "Enter advisor ID: ";
        in >> student.advisorID;
        return in;
    }

};
