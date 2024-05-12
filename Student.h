#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
    private:
        int id;
        string name;
        string level;
        string major;
        double gpa;
        int advisorID;

    public:
        Student();
        Student(int id , string name , string level , string major , double gpa , int advisorID);
        ~Student();

        //aux functions
        bool operator==(const Student &otherStudent);
        bool operator<(const Student &otherStudent);
        bool operator>(const Student &otherStudent);
        bool operator<=(const Student &otherStudent);
        bool operator>=(const Student &otherStudent);

        int getId();
        void printInfo();
        void setAdvisor(int newAdvisorID);


};


#endif 