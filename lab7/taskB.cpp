#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> slidingWindowMin(const vector<int> &arr, int n, int k)
{
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < n; ++i)
    {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    return result;
}

vector<int> slidingWindowMax(const vector<int> &arr, int n, int k)
{
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < n; ++i)
    {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> minValues = slidingWindowMin(arr, n, k);
    vector<int> maxValues = slidingWindowMax(arr, n, k);

    for (int i : minValues)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i : maxValues)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
