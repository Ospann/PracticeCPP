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

    // Заполнение массива объектами обоих классов
    people[0] = new Sportsman("Smith", "John", "Robert", 'M', 1998, "123 Main St", "Swimming", 3, 2);
    people[1] = new Sportsman("Johnson", "Alice", "Marie", 'F', 1995, "456 Elm St", "Tennis", 2, 5);
    // Добавьте другие объекты по необходимости...

    // Вывод информации о людях из массива
    for (int i = 0; i < numPeople; ++i)
    {
        people[i]->displayInfo();
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < numPeople; ++i)
    {
        delete people[i];
    }

    return 0;
}