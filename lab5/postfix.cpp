#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Функция evaluatePostfix принимает постфиксное арифметическое выражение в виде строки и вычисляет его результат.
 * @param expression Строка с постфиксным арифметическим выражением.
 * @return Результат вычислений.
 *
 * В данной функции используется стек для выполнения операций с числами.
 * Алгоритм проходит по каждому символу в строке, формируя числа и выполняя операции.
 * Ссылки:
 * stoi {https://cplusplus.com/reference/string/stoi/}
 * isdigit {https://cplusplus.com/reference/cctype/isdigit/}
 */
int evaluatePostfix(const string &expression)
{
    stack<int> stack; // Стек для хранения операндов и промежуточных результатов

    int pos = 0;
    // Проход по всем символам в строке
    while (pos < expression.size())
    {
        string token;

        // Формирование токена (числа или оператора)
        while (pos < expression.size() && expression[pos] != ' ')
        {
            token += expression[pos++];
        }

        // Пропуск пустых токенов
        if (token.empty())
        {
            pos++;
            continue;
        }

        // Если токен - число, помещаем его в стек
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            stack.push(stoi(token));
            continue;
        }

        // Если токен - оператор, выполняем соответствующую операцию
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

    return stack.top(); // Возвращаем верхний элемент стека, который содержит итоговый результат
}

int main()
{
    string expression;
    getline(cin, expression); // Ввод строки с постфиксным выражением

    int result = evaluatePostfix(expression); // Вычисление результата

    cout << result << endl; // Вывод результата

    return 0;
}
