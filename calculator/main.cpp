#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
double calculation(double operand1, double operand2, char operation);

int main()
{
    string equation;
    cout << "Enter (example: 10*5, 10+5, 10/5, 10-5): ";
    getline(cin, equation);

    istringstream iss(equation);

    double operand1, operand2;
    char operation;

    if (iss >> operand1 >> operation >> operand2)
    {
        double result = calculation(operand1, operand2, operation);
        cout << "Result: " << result << endl;
    }
    else
    {
        cout << "Format Error" << endl;
    }
    return 0;
}

/**
 * Funtion for calculation by operations and return result
*/
double calculation(double operand1, double operand2, char operation)
{
    double result;
    switch (operation)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        if (operand2 != 0)
        {
            result = operand1 / operand2;
        }
        else
        {
            cout << "Error!" << endl;
            return 1;
        }
        break;
    default:
        cout << "Error!" << endl;
        return 1;
    }

    return result;
}