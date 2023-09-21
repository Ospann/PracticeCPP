#include <iostream>
using namespace std;

class Array
{
private:
    int *arr;

public:
    int size;
    Array()
    {
        size = 1;
        arr = new int[size];
    }

    ~Array()
    {
        delete[] arr;
    }

    void addByIndex(int index, int value)
    {
        size = index + 1;
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }

    void deleteByIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
        }
        else
        {
            cout << "Invalid index." << endl;
        }
    }

    void sortByAcs()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int getElementByIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            cout << "Invalid index." << endl;
            return -1; 
        }
    }
};

int main()
{
    Array myArray;

    myArray.addByIndex(0, 5);
    myArray.addByIndex(1, 3);
    myArray.addByIndex(2, 7);
    myArray.addByIndex(3, 1);

    myArray.sortByAcs();

    for (int i = 0; i < myArray.size; i++)
    {
        cout << myArray.getElementByIndex(i) << " ";
    }

    return 0;
}
