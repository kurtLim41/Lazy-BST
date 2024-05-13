#include "DataBaseSystem.h"

DataBaseSystem::DataBaseSystem(){
    studentBST = new LazyBST<Student>();
    facultyBST = new LazyBST<Faculty>();
}

// void DataBaseSystem::run() {
//     int choice;
//     bool running = true;

//     while (running) {
//         cout << "\nMenu:\n"
//                   << "1. Print all students\n"
//                   << "2. Print all faculty\n"
//                   << "3. Find student by ID\n"
//                   << "4. Find faculty by ID\n"
//                   << "5. Add a new student\n"
//                   << "6. Delete a student\n"
//                   << "7. Add a new faculty\n"
//                   << "8. Delete a faculty\n"
//                   << "9. Change a student's advisor\n"
//                   << "10. Remove an advisee from a faculty\n"
//                   << "11. Exit\n"
//                   << "Enter your choice: ";
//         cin >> choice;
//         if(cin.fail()) {
//             cin.clear(); // Clears any error flags
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
//         }
//         switch (choice) {
//             case 1: printAllStudents(); break;
//             case 2: printAllFaculty(); break;
//             case 3: findStudentById(); break;
//             case 4: findFacultyById(); break;
//             case 5: addStudent(); break;
//             case 6: deleteStudent(); break;
//             case 7: addFaculty(); break;
//             case 8: deleteFaculty(); break;
//             case 9: changeStudentAdvisor(); break;
//             case 10: removeAdvisee(); break;
//             case 11:
//                 writeLog();
//                 running = false;
//                 break;
//             default:
//                 cout << "Invalid option, please try again.\n";
//                 break;
//         }
//     }
// }

// void DataBaseSystem::printAllStudents() {
//     studentBST->printTree();
// }

// void DataBaseSystem::printAllFaculty() {
//     facultyBST->printTree();
// }

// void DataBaseSystem::writeLog() {
//     ofstream logFile("runLog.txt");
//     if (logFile.is_open()) {
//         logFile << "Students:\n";
//         studentBST->printTreeToFile(logFile);
//         logFile << "\nFaculty:\n";
//         facultyBST->printTreeToFile(logFile);
//         logFile.close();
//         cout << "Log written successfully.\n";
//     } else {
//         cout << "Failed to open log file.\n";
//     }
// }

// Implement other methods...

