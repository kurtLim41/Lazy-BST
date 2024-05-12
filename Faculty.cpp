#include "Faculty.h"

Faculty::Faculty():id(0), name("na"), level("na"), department("na"), adviseesCount(1){
    advisees = new int[adviseesCount];
}

Faculty::Faculty(int id , string name , string level , string department , int *advisees , int count)
:id(id), name(name), level(level), department(department), adviseesCount(count){
    advisees = new int[adviseesCount];
}

bool Faculty::operator==(const Faculty &otherFaculty){
    return id==otherFaculty.id;
}

bool Faculty::operator<(const Faculty &otherFaculty){
    return id<otherFaculty.id;
}

bool Faculty::operator>(const Faculty &otherFaculty){
    return id>otherFaculty.id;
}

bool Faculty::operator<=(const Faculty &otherFaculty){
    return id<=otherFaculty.id;
}

bool Faculty::operator>=(const Faculty &otherFaculty){
    return id>=otherFaculty.id;
}

int Faculty::getId(){
    return id;
}

void Faculty::printInfo(){
    cout << "===================" << endl;
    cout << "Faculty ID #: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << department << endl;
    cout << "Advisees ID: ";
    for(int i = 0; i < adviseesCount; ++i){
        cout << advisees[i] << ", ";
    }
    cout << endl;
}
