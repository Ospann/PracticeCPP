#include <iostream>
using namespace std;
// variant 1

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
        if (size < index + 1)
        {
            size = index + 1;
        }

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
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
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

    void sortbyChoose()
    {
        int min = 0;
        int buf = 0;

        for (int i = 0; i < size; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                min = (arr[j] < arr[min]) ? j : min;
            }
            if (i != min)
            {
                buf = arr[i];
                arr[i] = arr[min];
                arr[min] = buf;
            }
        }
    }

    // Пузырьковый метод
    void sortByDesc()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                if (arr[j] < arr[j + 1])
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
    myArray.addByIndex(5, 2);

    // myArray.sortByAcs();
    // myArray.sortbyChoose();    
    myArray.sortByDesc();
    for (int i = 0; i < myArray.size; i++)
    {
        cout << myArray.getElementByIndex(i) << " ";
    }

    return 0;
}
