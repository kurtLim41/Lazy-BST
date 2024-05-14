#include "DataBaseSystem.h"

DataBaseSystem::DataBaseSystem(){
    studentBST = new LazyBST<Student>();
    facultyBST = new LazyBST<Faculty>();
}

DataBaseSystem::~DataBaseSystem(){
    delete studentBST;
    delete facultyBST;
}

void DataBaseSystem::run() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n"
                  << "1. Print all students\n"
                  << "2. Print all faculty\n"
                  << "3. Find student by ID\n"
                  << "4. Find faculty by ID\n"
                  << "5. Add a new student\n"
                  << "6. Delete a student\n"
                  << "7. Add a new faculty\n"
                  << "8. Delete a faculty\n"
                  << "9. Change a student's advisor\n"
                  << "10. Remove an advisee from a faculty\n"
                  << "11. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;
        if(cin.fail()) {
            cin.clear(); // Clears any error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer
        }
        switch (choice) {
            case 1: printAllStudents(); break;
            case 2: printAllFaculty(); break;
            case 3: findStudentById(); break;
            case 4: findFacultyById(); break;
            case 5: addStudent(); break;
            case 6: deleteStudent(); break;
            case 7: addFaculty(); break;
            case 8: deleteFaculty(); break;
            case 9: changeStudentAdvisor(); break;
            case 10: removeAdvisee(); break;
            case 11:
                writeLog();
                running = false;
                break;
            default:
                cout << "Invalid option, please try again.\n";
                break;
        }
    }
}

//option 1 
void DataBaseSystem::printAllStudents() {
    studentBST->printTree();
}

//option 2
void DataBaseSystem::printAllFaculty() {
    facultyBST->printTree();
}

//option 3
void DataBaseSystem::findStudentById(){
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    Student student(id);
    Student foundStudent;

    if (studentBST->get(student, foundStudent)) {
        cout << "Student found:" << endl;
        cout << foundStudent << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

//option 4
void DataBaseSystem::findFacultyById(){
     int id;
    cout << "Enter faculty ID: ";
    cin >> id;
    Faculty faculty(id);
    Faculty foundFaculty;

    if (facultyBST->get(faculty, foundFaculty)) {
        cout << "Faculty found:" << endl;
        cout << foundFaculty << endl;
    } else {
        cout << "Faculty not found." << endl;
    }
}

//option 5
void DataBaseSystem::addStudent(){
    Student student;
    cout << "Enter student details (ID, Name, Level, Major, GPA, Advisor ID):" << endl;
    cin >> student;

    cout << "created new student" << endl;
    // Check if the advisor ID exists in the faculty table
    Faculty advisor(student.getAdvisorID());
    Faculty foundAdvisor;
    cout << "advisor ID exists " << endl;

    if (facultyBST->get(advisor, foundAdvisor)) {
        // Add student to the tree
        studentBST->insert(student);

        // Add student ID as an advisee to the faculty member
        foundAdvisor.addAdvisee(student.getID());
        facultyBST->insert(foundAdvisor);
        facultyBST->deleteNode(advisor);
        
        cout << "Student added successfully." << endl;
    } else {
        cout << "Error: Advisor ID does not exist." << endl;
    }
}

//option 6
void DataBaseSystem::deleteStudent(){
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    Student student(id);
    Student foundStudent;

    if (studentBST->get(student, foundStudent)) {
        int advisorId = foundStudent.getAdvisorID();
        Faculty advisor(advisorId);
        Faculty foundAdvisor;

        // Remove student from advisor's list of advisees if advisor exists
        if (facultyBST->get(advisor, foundAdvisor)) {
            foundAdvisor.removeAdvisee(id);
            facultyBST->deleteNode(advisor);
            facultyBST->insert(foundAdvisor);
        }

        // Delete the student
        studentBST->deleteNode(student);
        cout << "Student deleted successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

//option 7
void DataBaseSystem::addFaculty(){
    Faculty faculty;
    cout << "Enter faculty details (ID, Name, Level, Department, Number of Advisees, Advisees):" << endl;
    cin >> faculty;

    // Check if the ID exists in the student table
    if (facultyBST->contains(Faculty(faculty.getID()))) {
        cout << "Error: ID already exists for a faculty member." << endl;
        return;
    }

    facultyBST->insert(faculty);
    cout << "Faculty member added successfully." << endl;
}

//option 8
void DataBaseSystem::deleteFaculty(){
    int id;
    cout << "Enter faculty ID to delete: ";
    cin >> id;
    Faculty faculty(id);
    Faculty foundFaculty;

    if (facultyBST->get(faculty, foundFaculty)) {
        cout << "found faculty" << endl;
        vector<int> advisees = foundFaculty.getAdviseesIDs();  // Use vector to get advisees
        if (!advisees.empty()) {
            int newAdvisorId;
            cout << "Faculty has advisees. Enter new advisor ID for these students: ";
            cin >> newAdvisorId;
            Faculty newAdvisor(newAdvisorId);
            Faculty foundNewAdvisor;

            if (!facultyBST->get(newAdvisor, foundNewAdvisor)) {
                cout << "New advisor ID not found." << endl;
                return;
            }

            // Reassign advisees
            for (int adviseeId : advisees) {  // Use range-based for loop for clarity
                Student student(adviseeId);
                Student foundStudent;

                if (studentBST->get(student, foundStudent)) {
                    foundStudent.setAdvisorID(newAdvisorId);  // Corrected function name
                    studentBST->deleteNode(student);
                    studentBST->insert(foundStudent);
                    foundNewAdvisor.addAdvisee(adviseeId);
                }
            }

            // Update new advisor in the tree
            facultyBST->deleteNode(newAdvisor);
            facultyBST->insert(foundNewAdvisor);
        }

        // Delete the old faculty member
        //facultyBST->deleteNode(foundFaculty);
        cout << "Faculty member deleted successfully." << endl;
    } else {
        cout << "Faculty not found." << endl;
    }
}

//option 9
void DataBaseSystem::changeStudentAdvisor(){
    int studentId, newAdvisorId;
    cout << "Enter student ID: ";
    cin >> studentId;
    cout << "Enter new advisor ID: ";
    cin >> newAdvisorId;

    Student student(studentId);
    Student foundStudent;

    if (studentBST->get(student, foundStudent)) {  // Check if the student exists
        // Directly update the student's advisor ID
        foundStudent.setAdvisorID(newAdvisorId);
        studentBST->insert(foundStudent); 
        studentBST->deleteNode(student);          // Remove the old student record      

        cout << "Advisor changed successfully." << endl;
    } else {
        cout << "Invalid student ID." << endl;
    }
}

//option 10
void DataBaseSystem::removeAdvisee() {
    int facultyId, adviseeId;
    cout << "Enter faculty ID: ";
    cin >> facultyId;
    cout << "Enter advisee ID: ";
    cin >> adviseeId;

    Faculty faculty(facultyId);
    Faculty foundFaculty;
    Student advisee(adviseeId);
    Student foundAdvisee;

    if (facultyBST->get(faculty, foundFaculty) && studentBST->get(advisee, foundAdvisee)) {
        foundFaculty.removeAdvisee(adviseeId);
        studentBST->deleteNode(advisee);
        foundAdvisee.setAdvisor(-1); // Or 0, depending on your convention
        studentBST->insert(foundAdvisee);

        // Update faculty table
        facultyBST->deleteNode(faculty);
        facultyBST->insert(foundFaculty);

        cout << "Advisee removed successfully." << endl;
    } else {
        cout << "Invalid faculty ID or advisee ID." << endl;
    }
}



//option 11
void DataBaseSystem::writeLog() {
    ofstream logFile("runLog.txt");
    if (logFile.is_open()) {
        logFile << "Students:\n";
        studentBST->printTreeToFile(logFile);
        logFile << "\nFaculty:\n";
        facultyBST->printTreeToFile(logFile);
        logFile.close();
        cout << "Log written successfully.\n";
    } else {
        cout << "Failed to open log file.\n";
    }
}

// Implement other methods...

