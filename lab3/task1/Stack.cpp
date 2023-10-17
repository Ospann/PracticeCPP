#include "Stack.h"

// Конструктор класса Stack
template <typename T>
Stack<T>::Stack(int capacity)
{
    this->capacity = capacity;
    a = new T[capacity];
    n = 0;
}

// Деструктор класса Stack
template <typename T>
Stack<T>::~Stack()
{
    delete[] a;
}

// Проверяет, пуст ли стек
template <typename T>
bool Stack<T>::empty()
{
    return n == 0;
}

// Проверяет, заполнен ли стек
template <typename T>
bool Stack<T>::full()
{
    return n == capacity;
}

// Добавляет элемент в стек
template <typename T>
void Stack<T>::push(T item)
{
    if (full())
    {
        throw runtime_error("Array is full"); // Бросаем исключение, если стек заполнен
    }
    else
    {
        a[n++] = item;
    }
}

// Изменяет размер стека
template <typename T>
void Stack<T>::resize(int new_capacity)
{
    if (new_capacity <= 0)
    {
        throw runtime_error("New size too small");
    }

    T *new_a = new T[new_capacity];

    for (int i = 0; i < n; ++i)
    {
        new_a[i] = a[i];
    }

    delete[] a;

    a = new_a;
    capacity = new_capacity;
}

// Извлекает элемент из стека
template <typename T>
T Stack<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Array is empty"); // Бросаем исключение, если стек пуст
    }
    return a[--n];
}

// Возвращает вершину стека без удаления
template <typename T>
T Stack<T>::top()
{
    if (empty())
    {
        throw runtime_error("Array is empty"); // Бросаем исключение, если стек пуст
    }
    return a[n - 1];
}

// Перегрузка оператора вывода для класса Stack
template <typename T>
ostream &operator<<(ostream &os, const Stack<T> &st)
{
    for (int i = 0; i < st.n; ++i)
    {
        os << st.a[i] << " ";
    }
    return os;
}
