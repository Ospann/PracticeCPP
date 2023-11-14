#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int value)
    {
        stack1.push(value);
    }

    int dequeue()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty())
        {
            int frontValue = stack2.top();
            stack2.pop();
            return frontValue;
        }
        else
        {
            return -1;
        }
    }

    int front()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty())
        {
            return stack2.top();
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    QueueUsingTwoStacks queue;

    int q;
    cin >> q;

    while (q--)
    {
        int queryType;
        cin >> queryType;

        switch (queryType)
        {
        case 1:
            int value;
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            cout << queue.front() << endl;
            break;

        default:
            cerr << "Invalid query type" << endl;
            break;
        }
    }

    return 0;
}
