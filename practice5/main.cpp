#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

int main()
{
    Student student1("Ospanov", "Arystan", "Ruslanovich", 'M', 2004, "Koktem 2", 12345, "Computer Science", 3.7);
    student1.displayInfo();

    return 0;
}
 