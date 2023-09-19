#include <iostream>
using namespace std;

int main()
{
    int M, N;

    cout << "Enter size for array (M): ";
    cin >> M;

    cout << "Enter size for array (N): ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Enter elements for array A:\n";
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i];
    }

    cout << "Enter elements for array B:\n";
    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    int* uniqueElements = new int[M];
    int uniqueCount = 0;

    for (int i = 0; i < M; ++i)
    {
        bool isUnique = true;

        for (int j = 0; j < N; ++j)
        {
            if (A[i] == B[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            uniqueElements[uniqueCount] = A[i];
            uniqueCount++;
        }
    }

    cout << "Unique elements only in A:\n";
    for (int i = 0; i < uniqueCount; ++i)
    {
        cout << uniqueElements[i] << " ";
    }

    cout << endl;

    delete[] A;
    delete[] B;
    delete[] uniqueElements;

    return 0;
}
