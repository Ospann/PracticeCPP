#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x)
    {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }

    void pop()
    {
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }
        mainStack.pop();
    }

    int getMin() const
    {
        return minStack.top();
    }
};

int main()
{
    int n;
    cin >> n;

    MinStack myStack;

    for (int i = 0; i < n; ++i)
    {
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            int x;
            cin >> x;
            myStack.push(x);
        }
        else if (operation == 2)
        {
            myStack.pop();
        }
        else if (operation == 3)
        {
            cout << myStack.getMin() << endl;
        }
    }

    return 0;
}
