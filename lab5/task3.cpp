#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks
{
private:
    stack<int> stack1; // Первый стек для добавления элементов (enqueue)
    stack<int> stack2; // Второй стек для извлечения элементов (dequeue и front)

public:
    // Добавление элемента в очередь
    void enqueue(int value)
    {
        stack1.push(value);
    }

    // Извлечение элемента из очереди
    int dequeue()
    {
        // Если второй стек пуст, перекладываем элементы из первого стека во второй
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Если второй стек не пуст, извлекаем элемент
        if (!stack2.empty())
        {
            int frontValue = stack2.top();
            stack2.pop();
            return frontValue;
        }
        else
        {
            return -1; // Очередь пуста
        }
    }

    // Получение значения первого элемента в очереди без его извлечения
    int front()
    {
        // Если второй стек пуст, перекладываем элементы из первого стека во второй
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Если второй стек не пуст, возвращаем значение верхнего элемента
        if (!stack2.empty())
        {
            return stack2.top();
        }
        else
        {
            return -1; // Очередь пуста
        }
    }
};

int main()
{
    QueueUsingTwoStacks queue;

    int q;
    cin >> q; // Ввод количества запросов

    // Обработка запросов
    while (q--)
    {
        int queryType;
        cin >> queryType; // Тип запроса

        switch (queryType)
        {
        case 1:
            int value;
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue(); // Удаление элемента из очереди
            break;

        case 3:
            cout << queue.front() << endl; // Вывод значения первого элемента
            break;

        default:
            cerr << "Недопустимый тип запроса" << endl;
            break;
        }
    }

    return 0;
}
