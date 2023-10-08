#include "Stack.h"

template <typename T>
Stack<T>::Stack(int capacity)
{
    this->capacity = capacity;
    a = new T[capacity];
    n = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] a;
}

template <typename T>
bool Stack<T>::empty()
{
    return n == 0;
}

template <typename T>
bool Stack<T>::full()
{
    return n == capacity;
}

template <typename T>
void Stack<T>::push(T item)
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

template <typename T>
void Stack<T>::resize(int new_capacity)
{
    if (new_capacity <= 0)
    {
        cout << "Invalid capacity" << endl;
        return;
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

template <typename T>
T Stack<T>::pop()
{
    if (empty())
    {
        cout << "Stack is empty" << endl;
        return T();
    }
    return a[--n];
}

template <typename T>
T Stack<T>::top()
{
    if (empty())
    {
        cout << "Stack is empty" << endl;
        return T();
    }
    return a[n - 1];
}

template <typename T>
ostream &operator<<(ostream &os, const Stack<T> &st)
{
    for (int i = 0; i < st.n; ++i)
    {
        os << st.a[i] << " ";
    }
    return os;
}
