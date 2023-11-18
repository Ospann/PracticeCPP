#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the bracket sequence is balanced
bool checkingBracket(const string &sequence)
{
    stack<char> bracketStack; // Stack to keep track of opening brackets

    // Loop through each character in the input string
    for (char bracket : sequence)
    {
        // If the current character is an opening bracket, push it onto the stack
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            bracketStack.push(bracket);
            continue;
        }

        // If the stack is empty and we encounter a closing bracket, the sequence is unbalanced
        if (bracketStack.empty())
        {
            return false;
        }

        // Pop the top element from the stack
        char top = bracketStack.top();
        bracketStack.pop();

        // Check if the current closing bracket matches the corresponding opening bracket
        if ((bracket == ')' && top != '(') ||
            (bracket == ']' && top != '[') ||
            (bracket == '}' && top != '{'))
        {
            return false;
        }
    }

    // Check if there are any remaining opening brackets in the stack
    return bracketStack.empty();
}

int main()
{
    string bracketSequence;
    cin >> bracketSequence; // Input the bracket sequence

    // Output "yes" if the bracket sequence is balanced, otherwise output "no"
    cout << (checkingBracket(bracketSequence) ? "yes" : "no") << endl;

    return 0;
}

// This program uses a stack to check whether the input bracket sequence is balanced or not.
// It iterates through each character in the sequence, pushing opening brackets onto the stack
// and popping the stack for each closing bracket, checking if they match.
// The ternary operator is used to output "yes" if the sequence is balanced and "no" otherwise.
