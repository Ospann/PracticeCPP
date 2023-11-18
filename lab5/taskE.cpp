#include <iostream>
#include <stack>

using namespace std;

void insertion(int n, const string &lrString)
{
    stack<int> s;
    int counter = 1;

    for (int i = 0; i < n; ++i)
    {
        if (lrString[i] == 'L')
        {
            cout << counter++ << " ";
        }
        else if (lrString[i] == 'R')
        {
            s.push(counter++);
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    int n;
    cin >> n;

    string lrString;
    cin >> lrString;

    insertion(n, lrString);

    return 0;
}
