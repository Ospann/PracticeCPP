#include <iostream>

using namespace std;

int main()
{
    int M, N;

    cout << "Enter size for array (M): ";
    cin >> M;

    cout << "Enter size for array (N): ";
    cin >> N;

    int *A = new int[M];
    int *B = new int[N];

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

    int *uniqueElementsA = new int[M];
    int *uniqueElementsB = new int[N];
    int uniqueCountA = 0;
    int uniqueCountB = 0;

    for (int i = 0; i < M; ++i)
    {
        bool isUnique = true;

        for (int j = 0; j < uniqueCountA; ++j)
        {
            if (A[i] == uniqueElementsA[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            uniqueElementsA[uniqueCountA] = A[i];
            uniqueCountA++;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        bool isUnique = true;

        for (int j = 0; j < uniqueCountB; ++j)
        {
            if (B[i] == uniqueElementsB[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            uniqueElementsB[uniqueCountB] = B[i];
            uniqueCountB++;
        }
    }

    cout << "Unique elements in arrays A:\n";
    for (int i = 0; i < uniqueCountA; ++i)
    {
        cout << uniqueElementsA[i] << " ";
    }

    cout << "\nUnique elements in arrays B:\n";
    for (int i = 0; i < uniqueCountB; ++i)
    {
        cout << uniqueElementsB[i] << " ";
    }

    cout << endl;

    delete[] A;
    delete[] B;
    delete[] uniqueElementsA;
    delete[] uniqueElementsB;

    return 0;
}
