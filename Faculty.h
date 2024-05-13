#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Faculty {
private:
    int facultyID;
    string name;
    string level;
    string department;
    vector<int> adviseesIDs;

public:
    Faculty(int id, string n, string lvl, string dept){
        facultyID = id;
        name = n;
        level = lvl;
        department = dept;
        adviseesIDs = {};
    }
        

    // Accessor functions
    int getID() const { 
        return facultyID; 
    }
    string getName() const { 
        return name; 
    }
    string getLevel() const { 
        return level; 
    }
    string getDepartment() const { 
        return department; 
    }
    vector<int> getAdviseesIDs() const { 
        return adviseesIDs; 
    }

    // Add an advisee to the list
    void addAdvisee(int studentID) {
        adviseesIDs.push_back(studentID);
    }

    // Remove an advisee from the list
    bool removeAdvisee(int studentID) {
        auto it = find(adviseesIDs.begin(), adviseesIDs.end(), studentID);
        if (it != adviseesIDs.end()) {
            adviseesIDs.erase(it);
            return true;
        }
        return false;
    }

    // Overloaded operators for comparisons based on faculty ID
    bool operator==(const Faculty& other) const { return facultyID == other.facultyID; }
    bool operator<(const Faculty& other) const { return facultyID < other.facultyID; }
    bool operator>(const Faculty& other) const { return facultyID > other.facultyID; }

    // Display faculty information
    void display() const {
        cout << "Faculty ID: " << facultyID
                  << ", Name: " << name
                  << ", Level: " << level
                  << ", Department: " << department
                  << ", Advisees IDs: ";
        for (int id : adviseesIDs) {
            cout << id << " ";
        }
        cout << endl;
    }
};
