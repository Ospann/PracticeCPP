#include <iostream>
using namespace std;

int main()
{
    int arraySize = 3;
    int* dynamicArray = new int[arraySize];
    int newElement;

    dynamicArray[0] = 1;
    dynamicArray[1] = 2;
    dynamicArray[2] = 3;

    cout << "Enter new element in array: ";
    cin >> newElement;

    int* newArray = new int[arraySize + 1];

    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = dynamicArray[i];
    }

    newArray[arraySize] = newElement;

    delete[] dynamicArray;
    dynamicArray = newArray;
    arraySize++;

    cout << "Your array: ";

    for (int i = 0; i < arraySize; i++)
    {
        cout << dynamicArray[i] << " ";
    }

    cout << endl;

    delete[] dynamicArray;

    return 0;
}
