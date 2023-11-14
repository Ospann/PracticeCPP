#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    stack<int> st;
    int *result = new int[n]();

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            result[i] = st.top() + 1;
        }

        st.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }

    delete[] arr;
    delete[] result;

    return 0;
}
