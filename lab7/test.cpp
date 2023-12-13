#include <iostream>
using namespace std;

string heap(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
        {
            return "NO";
        }
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << heap(arr, n) << endl;

    return 0;
}