#include <iostream>
#include <set>
#include <vector>

using namespace std; 

int main()
{
    int M, N;

    cout << "Enter size for array (M): ";
    cin >> M;

    cout << "Enter size for array (N): ";
    cin >> N;

    vector<int> A(M);
    vector<int> B(N);

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

    set<int> uniqueElements;
    
    vector<int> result;
    
    for (int i = 0; i < M; ++i) {
        uniqueElements.insert(A[i]);
    }
    
    for (int i = 0; i < N; ++i) {
        if (uniqueElements.find(B[i]) == uniqueElements.end()) {
            result.push_back(B[i]);
        }
    }
    
    cout << "Unique elements in arrays:\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    cout << endl;

    return 0;
}
