#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>;
using namespace std;

class Faculty{
    private:
        int id;
        string name;
        string level;
        string department;
        int *advisees;
        int adviseesCount;

    public:
        Faculty();
        Faculty(int id , string name , string level , string department , int *advisees , int count); 
        ~Faculty();

        //aux functions
        bool operator==(const Faculty &otherFaculty);
        bool operator<(const Faculty &otherFaculty);
        bool operator>(const Faculty &otherFaculty);
        bool operator<=(const Faculty &otherFaculty);
        bool operator>=(const Faculty &otherFaculty);

        int getId();
        void printInfo();
    
};


#endif 