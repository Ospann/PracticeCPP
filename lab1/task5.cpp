#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> dynamicArray;
    int index;
    dynamicArray.push_back(1);
    dynamicArray.push_back(2);
    dynamicArray.push_back(3);

    cout << "Enter index in array, which will be deleted: ";
    cin >> index;
    dynamicArray.erase(dynamicArray.begin() + index);

    cout << "Your array: ";

    for (int i = 0; i < dynamicArray.size(); i++)
    {
        cout << dynamicArray[i] << " ";
    }

    cout << endl;

    return 0;
}
