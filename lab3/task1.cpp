#include <iostream>
using namespace std;

class FixedCapacityStack
{
private:
    int *a; // массив, содержащий элементы Стека
    int n;  // количество элементов в Стеке
    int capacity; // максимальная вместимость стека
public:
    // Конструктор: создать пустой динамический массив с размером, равным capacity
    FixedCapacityStack(int capacity)
    {
        this->capacity = capacity;
        a = new int[capacity];
        n = 0; // Начальное количество элементов в стеке равно 0
    };

    // Деструктор: освободить память массива (delete)
    ~FixedCapacityStack()
    {
        delete[] a;
    }

    // Проверка на пустоту стека
    bool empty()
    {
        return n == 0;
    }

    // Проверка на полноту стека
    bool full()
    {
        return n == capacity;
    }

    // Добавить элемент в стек
    void push(int item)
    {
        if (full())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            a[n++] = item; 
        }
    }

    // Удалить вершину стека
    int pop()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return a[--n]; 
    }

    // Вернуть значение вершины стека
    int top()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return a[n - 1];
    }

    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream &operator<<(ostream &os, FixedCapacityStack &st)
    {
        for (int i = 0; i < st.n; ++i)
        {
            os << st.a[i] << " ";
        }
        return os;
    }
};

int main()
{
    FixedCapacityStack mystack(5);
    for (int i = 1; i <= 5; ++i)
    {
        mystack.push(i);
    }
    // Вывод элементов стека
    cout << mystack << endl;

    // Очищение стека – удаление всех элементов
    while (!mystack.empty())
    {
        mystack.pop();
    }
    cout << "After delete:" << mystack.empty() << endl;

    return 0;
}
