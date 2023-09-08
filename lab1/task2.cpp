#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> dynamicArray;
    int newElement;
    dynamicArray.push_back(1);
    dynamicArray.push_back(2);
    dynamicArray.push_back(3);

    cout << "Enter new element in array: ";
    cin >> newElement;
    dynamicArray.push_back(newElement);

    cout << "Your array: ";

    for (int i = 0; i < dynamicArray.size(); i++)
    {
        cout << dynamicArray[i] << " ";
    }

    cout << endl;

    return 0;
}
