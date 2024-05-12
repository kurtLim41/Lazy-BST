#ifndef DATABASESYSTEM_H
#define DATABASESYSTEM_H

#include <iostream>
#include "LazyBst.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

class DataBaseSystem{
    private:
        LazyBST<Student> *studentTable;
        LazyBST<Faculty> *facultyTable;

    public:
        DataBaseSystem();
        ~DataBaseSystem();

        //core functions 
        void runSystem();
        void printAllStudents();  //option 1
        void printAllFaculty();  //option 2
        void findStudent(int studentID);  //option 3
        void findFaculty(int facultyID);  //option 4
        void addStudent(Student newStudent);  //option 5
        void deleteStudent(int studentID);  //option 6
        void addFaculty(Faculty newFaculty);  //option 7
        void deleteFaculty(int facultyID);  //option 8
        void changeStudentAdvisor(int studentID , int facultyID);  //option 9
        void removeAdvisee(int facultyID , int studentID);  //option 10
        void exitProgram();




};


#endif 