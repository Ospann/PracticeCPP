#include <iostream>
#include <string>
#include "Human.h"
using namespace std;

class Student : public Human
{
public:
    // Конструктор по умолчанию
    Student()
    {
        studentID = 0;
        major = "";
        gpa = 0.0;
    }

    // Конструктор с параметрами
    Student(string last, string first, string pat, char gen, int year, string addr, int id, string mjr, double g)
        : Human(last, first, pat, gen, year, addr)
    {
        studentID = id;
        major = mjr;
        gpa = g;
    }

    // Деструктор
    ~Student()
    {
        // Пока не нужно освобождать какие-либо ресурсы
    }

    // Дополнительные методы и поля, характерные для студента
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

private:
    int studentID;
    string major;
    double gpa;
};

int main()
{
    Student student1("Smith", "John", "Robert", 'M', 1998, "123 Main St", 12345, "Computer Science", 3.7);
    student1.printStudentInfo();

    return 0;
}
