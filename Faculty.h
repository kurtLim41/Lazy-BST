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
    Faculty(){
        facultyID = 0;
        name = "na";
        level = "na";
        department = "na";
        adviseesIDs = {};
    }

    Faculty(int id) {
        facultyID = id;
        name = "na";
        level = "na";
        department = "na";
        adviseesIDs = {};
    }

    Faculty(int id, string n, string lvl, string dept){
        facultyID = id;
        name = n;
        level = lvl;
        department = dept;
        adviseesIDs = {};
    }

    Faculty(const Faculty &other)
        : facultyID(other.facultyID), name(other.name), level(other.level), department(other.department){
    }

    ~Faculty() {
    }

    Faculty &operator=(const Faculty &other) {
        if (this != &other) {
            facultyID = other.facultyID;
            name = other.name;
            level = other.level;
            department = other.department;
            adviseesIDs = other.adviseesIDs; // Vector assignment handles deep copying
        }
        return *this;
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

     // Overloaded Operators
    bool operator==(const Faculty &other) const {
        return facultyID == other.facultyID;
    }

    bool operator<(const Faculty &other) const {
        return facultyID < other.facultyID;
    }

    bool operator>(const Faculty &other) const {
        return facultyID > other.facultyID;
    }

    bool operator<=(const Faculty &other) const {
        return facultyID <= other.facultyID;
    }

    bool operator>=(const Faculty &other) const {
        return facultyID >= other.facultyID;
    }

    bool operator!=(const Faculty &other) const {
        return facultyID != other.facultyID;
    }




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

    friend::ostream& operator<<(ostream& os, const Faculty& faculty) {
    os << "ID: " << faculty.facultyID
       << ", Name: " << faculty.name
       << ", Level: " << faculty.level
       << ", Major: " << faculty.department
       << ", Advisees ID: ";
       for (int id : faculty.adviseesIDs) {
            os << id << " ";
        }
        os << endl;
    return os;
    }

    friend istream &operator>>(istream &in, Faculty &faculty) {
        // Clear existing advisees, if any
        faculty.adviseesIDs.clear();

        cout << "Enter ID: ";
        in >> faculty.facultyID;
        in.ignore();
        cout << "Enter name: ";
        getline(in, faculty.name);
        cout << "Enter level: ";
        getline(in, faculty.level);
        cout << "Enter department: ";
        getline(in, faculty.department);
        int numAdvisees;
        cout << "Enter number of advisees: ";
        in >> numAdvisees;
        for (int i = 0; i < numAdvisees; ++i) {
            int adviseeID;
            cout << "Enter advisee ID " << i + 1 << ": ";
            in >> adviseeID;
            faculty.addAdvisee(adviseeID); // Add advisee
        }
        return in;
    }


};
