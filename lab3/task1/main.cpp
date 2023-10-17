#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> mystack(5);
    for (int i = 1; i <= 5; ++i)
    {
        mystack.push(i);
    }
    // Вывод элементов стека
    cout << mystack << endl;
    try
    {
        // Очищение стека – удаление всех элементов
        while (!mystack.empty())
        {
            mystack.pop();
        }
        cout << "After delete:" << mystack.empty() << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
