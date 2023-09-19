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

    cout << "Common elements in arrays:\n";
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (A[i] == B[j])
            {
                cout << A[i] << " ";
                break;
            }
        }
    }

    cout << endl;

    // Don't forget to deallocate memory for the arrays
    delete[] A;
    delete[] B;

    return 0;
}
