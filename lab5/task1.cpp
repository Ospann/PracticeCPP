#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkingBracket(const string &sequence)
{
    stack<char> bracketStack;

    // Loop by separate symbol
    for (char bracket : sequence)
    {
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            bracketStack.push(bracket);
            continue;
        }

        if (bracketStack.empty())
        {
            return false;
        }

        char top = bracketStack.top();
        bracketStack.pop();

        if ((bracket == ')' && top != '(') ||
            (bracket == ']' && top != '[') ||
            (bracket == '}' && top != '{'))
        {
            return false;
        }
    }

    return bracketStack.empty();
}

int main()
{
    string bracketSequence;
    cin >> bracketSequence;

    cout << (checkingBracket(bracketSequence) ? "yes" : "no") << endl;

    return 0;
}

// using ternary operator and Stack. Firstly, I made a loop by separate symbols, and if firs symbol in string is (,{,[, so i push it to bracketStack and continue loop, next I checking (), {}, [] placed close or not