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

    set<int> uniqueB(B.begin(), B.end());
    
    vector<int> result;
    
    for (int i = 0; i < M; ++i) {
        if (uniqueB.find(A[i]) == uniqueB.end()) {
            result.push_back(A[i]);
            uniqueB.insert(A[i]); 
        }
    }
    
    cout << "Unique elements only in A :\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    cout << endl;

    return 0;
}
