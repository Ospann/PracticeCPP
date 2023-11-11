#include <iostream>
using namespace std;
int main()
{
    int N;
    string S;
    cin >> N >> S;

    const int MAX_N = 500000;
    int left[MAX_N], right[MAX_N];
    int leftSize = 0, rightSize = 0;

    right[rightSize++] = 0;

    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'L')
        {
            left[leftSize++] = i + 1;
        }
        else if (S[i] == 'R')
        {
            right[rightSize++] = i + 1;
        }
    }

    for (int i = 0; i < leftSize; ++i)
    {
        cout << left[i] << " ";
    }
    for (int i = 0; i < rightSize; ++i)
    {
        cout << right[i] << " ";
    }

    return 0;
}
