#include <iostream>

using namespace std;

int main()
{
    int arraySize, indexToDelete;
    
    cout << "Enter the size of the array: ";
    cin >> arraySize;
    
    int* dynamicArray = new int[arraySize];
    
    cout << "Enter " << arraySize << " elements for the array: ";
    for (int i = 0; i < arraySize; ++i)
    {
        cin >> dynamicArray[i];
    }

    cout << "Enter index in array, which will be deleted: ";
    cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < arraySize)
    {
        for (int i = indexToDelete; i < arraySize - 1; ++i)
        {
            dynamicArray[i] = dynamicArray[i + 1];
        }

        arraySize--; 

        int *newArray = new int[arraySize];
        for (int i = 0; i < arraySize; ++i)
        {
            newArray[i] = dynamicArray[i];
        }

        delete[] dynamicArray;
        dynamicArray = newArray;
    }
    else
    {
        cout << "Invalid index. Element not deleted." << endl;
    }

    cout << "Your array: ";

    for (int i = 0; i < arraySize; i++)
    {
        cout << dynamicArray[i] << " ";
    }

    cout << endl;

    delete[] dynamicArray;

    return 0;
}
