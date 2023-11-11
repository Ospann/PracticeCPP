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
