#include <iostream>
#include <stack>

using namespace std;

// Class representing a stack that supports finding the minimum element efficiently
class MinStack
{
private:
    stack<int> mainStack; // Main stack to store elements
    stack<int> minStack;  // Auxiliary stack to keep track of the minimum element

public:
    // Function to push an element onto the stack
    void push(int x)
    {
        mainStack.push(x); // Push the element onto the main stack

        // If the minStack is empty or the new element is less than or equal to the current minimum, push it onto minStack
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }

    // Function to pop the top element from the stack
    void pop()
    {
        // If the top elements of mainStack and minStack are equal, pop from minStack
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }
        mainStack.pop(); // Always pop from mainStack
    }

    // Function to get the minimum element in the stack
    int getMin() const
    {
        return minStack.top(); // Return the top element of minStack
    }
};

int main()
{
    int n;
    cin >> n; // Input the number of operations

    MinStack myStack; // Create an instance of the MinStack class

    // Loop through each operation
    for (int i = 0; i < n; ++i)
    {
        int operation;
        cin >> operation; // Input the type of operation

        // Perform the corresponding operation based on the input
        if (operation == 1)
        {
            int x;
            cin >> x; // Input the value to be pushed onto the stack
            myStack.push(x);
        }
        else if (operation == 2)
        {
            myStack.pop(); // Pop the top element from the stack
        }
        else if (operation == 3)
        {
            cout << myStack.getMin() << endl; // Output the minimum element in the stack
        }
    }

    return 0;
}
