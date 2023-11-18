#include <iostream>
#include <stack>

using namespace std;

void pushAndReverse(stack<int> &mystack, int value)
{
    stack<int> tempStack;

    while (!mystack.empty())
    {
        tempStack.push(mystack.top());
        mystack.pop();
    }

    mystack.push(value);

    while (!tempStack.empty())
    {
        mystack.push(tempStack.top());
        tempStack.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    stack<int> mystack;

    for (int i = 0; i < n; ++i)
    {
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            int x, c;
            cin >> x >> c;

            c = min(c, n);
            for (int j = 0; j < c; ++j)
            {
                pushAndReverse(mystack, x);
            }
        }
        else if (operation == 2)
        {
            int c;
            int sum = 0;
            cin >> c;
            c = min(c, n);

            for (int j = 0; j < c; ++j)
            {
                sum += mystack.top();
                mystack.pop();
            }
            cout << sum << endl;
        }
    }

    return 0;
}
