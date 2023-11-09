#include <iostream>
#include <string>
#include "Human.h"
#include "Sportsman.h"
#include "Student.h"

using namespace std;

int main()
{
    const int numPeople = 5;
    Human *people[numPeople];

    people[0] = new Sportsman("Ospanov", "Arystan", "Ruslanovich", 'M', 2004, "Koktem 2", "Swimming", 3, 2);
    people[1] = new Sportsman("Omarov", "Askhat", "Tleubekovich", 'M', 1995, "456 Elm St", "Tennis", 2, 5);
    people[2] = new Student("Tleubekovich", "Arman", "Jeksenbekov", 'M', 2003, "Timiryzevo", 12345, "Computer Science", 3.3);
    people[3] = new Student("Kim", "Nurzat", "Omarova", 'F', 2002, "Abay 67", 23342, "Medicine", 3.65);
    people[4] = new Student("Ospanova", "Saule", "Kraulova", 'F', 1999, "Abay 22", 90099, "GameDev", 3.7);

    for (int i = 0; i < numPeople; ++i)
    {
        people[i]->displayInfo();
        cout << endl;
    }

    return 0;
}