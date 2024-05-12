#include "DataBaseSystem.h"
#include <fstream>
#include <string>

DataBaseSystem::DataBaseSystem(){
    studentTable = new LazyBST<Student>();
    facultyTable = new LazyBST<Faculty>();
}

DataBaseSystem::~DataBaseSystem(){
    delete studentTable;
    delete facultyTable;
}

void DataBaseSystem::runSystem(){
    int option = -1;
    //loops indefiently till exit is choosen 
    while(true){
        cout << "Menu options, enter number corresponding to choice" << endl;
        cout << "1. Print all students and their information" << endl;
        cout << "2. Print all faculty and their information" << endl;
        cout << "3. Find and display student information given the student id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Add a new student" << endl;
        cout << "6. Delete a student given the id" << endl;
        cout << "7. Add a new faculty member" << endl;
        cout << "8. Delete a facutly member given the id" << endl;
        cout << "9. Change a student's advisor given the student id and the new faculty id" << endl;
        cout << "10. Remove an adivsee from a faculty member given the ids" << endl;
        cout << "11. Exit program" << endl;
        cout << "====================================" << endl;
        
        //get option from console 
        cin >> option;

        // switch statement for all options 
        switch(option){
            case 1: printAllStudents(); break;
            case 2:
            case 3: 
            case 4: 
            case 5:
            case 6: 
            case 7:
            case 8:
            case 9:
            case 10:
            case 11: exitProgram(); return;
            default:
                cout << "Invalid option, please pick an option displayed on menu" << endl;
                break;
        }
    }
}

//option 1
void DataBaseSystem::printAllStudents() {
    studentTable->printTree();
}







//option 11
void DataBaseSystem::exitProgram(){
    ofstream fout ("runLog.txt");
    if(!fout){
        cerr << "Error, cant open output file" << endl;
    }

    //print students info
    fout << "Students information" << endl;
    studentTable->printTreeToFile(fout);
    fout << endl;

    //print faculty info 
    fout << "Faculty information" << endl;
    facultyTable->printTreeToFile(fout);

    fout.close();
}