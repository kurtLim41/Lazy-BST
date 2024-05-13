#ifndef DATABASESYSTEM_H
#define DATABASESYSTEM_H

#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataBaseSystem {
private:
    LazyBST<Student> *studentBST;
    LazyBST<Faculty> *facultyBST;

    

public:
    void run();
    DataBaseSystem();
    ~DataBaseSystem();

    void printMenu();
    void printAllStudents();
    void printAllFaculty();
    void findStudentById();
    void findFacultyById();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeStudentAdvisor();
    void removeAdvisee();
    void writeLog();
};

#endif