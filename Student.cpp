#include "Student.h"

//constructor 
Student::Student():id(0), name("na"), level("na"), major("na"), gpa(0) , advisorID(0){}

Student::Student(int id , string name , string level , string major , double gpa , int advisorID)
:id(id), name(name), level(level), major(major), gpa(gpa) , advisorID(advisorID){}

//deconstructor 
Student::~Student(){}

bool Student::operator==(const Student &otherStudent){
    return id==otherStudent.id;
}

bool Student::operator<(const Student &otherStudent){
    return id<otherStudent.id;
}

bool Student::operator>(const Student &otherStudent){
    return id>otherStudent.id;
}

bool Student::operator<=(const Student &otherStudent){
    return id<=otherStudent.id;
}

bool Student::operator>=(const Student &otherStudent){
    return id>=otherStudent.id;
}

int Student::getId(){
    return id;
}

void Student::printInfo(){
    cout << "===================" << endl;
    cout << "Student ID #: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Grade: " << level << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Students Advisor ID #: " << advisorID << endl;
}

void Student::setAdvisor(int newAdvisorID){
    advisorID = newAdvisorID;
}

