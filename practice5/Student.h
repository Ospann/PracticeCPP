#include <iostream>
#include <string>
#include "Human.h"
using namespace std;

class Student : public Human
{
private:
    int studentID;
    string major;
    double gpa;

public:
    Student()
    {
        studentID = 0;
        major = "";
        gpa = 0.0;
    }

    Student(string last, string first, string pat, char gen, int year, string addr, int id, string mjr, double g)
        : Human(last, first, pat, gen, year, addr)
    {
        studentID = id;
        major = mjr;
        gpa = g;
    }

    ~Student()
    {
    }

    void setStudentID(int id)
    {
        studentID = id;
    }

    int getStudentID() const
    {
        return studentID;
    }

    void setMajor(string mjr)
    {
        major = mjr;
    }

    string getMajor() const
    {
        return major;
    }

    void setGPA(double g)
    {
        gpa = g;
    }

    double getGPA() const
    {
        return gpa;
    }

    void printStudentInfo()
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
    }

    void displayInfo()
    {
        cout << "Student Information:" << endl;
        cout << "Name: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Birth Year: " << getBirthYear() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "student Id: " << studentID << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
    }
};
