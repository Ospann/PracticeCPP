#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std; 

template <typename T>
class Stack
{
private:
    T *a;
    int n;
    int capacity;

public:
    Stack(int capacity);
    ~Stack();

    bool empty();
    bool full();
    void push(T item);
    void resize(int new_capacity);
    T pop();
    T top();

    friend std::ostream &operator<<(std::ostream &os, const Stack<T> &st)
    {
        for (int i = 0; i < st.n; ++i)
        {
            os << st.a[i] << " ";
        }
        return os;
    }
};

#include "Stack.cpp"

#endif
