#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 *
 *
 * stoi {https://cplusplus.com/reference/string/stoi/}
 * isdigit {https://cplusplus.com/reference/cctype/isdigit/}
 */
int evaluatePostfix(const string &expression)
{
    stack<int> stack;

    int pos = 0;
    while (pos < expression.size())
    {
        string token;

        while (pos < expression.size() && expression[pos] != ' ')
        {
            token += expression[pos++];
        }

        if (token.empty())
        {
            pos++;
            continue;
        }

        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            stack.push(stoi(token));
            continue;
        }

        int operand2 = stack.top();
        stack.pop();
        int operand1 = stack.top();
        stack.pop();

        if (token == "+")
        {
            stack.push(operand1 + operand2);
        }
        else if (token == "-")
        {
            stack.push(operand1 - operand2);
        }
        else if (token == "*")
        {
            stack.push(operand1 * operand2);
        }
    }

    return stack.top();
}

int main()
{
    string expression;
    getline(cin, expression);

    int result = evaluatePostfix(expression);

    cout << result << endl;

    return 0;
}
