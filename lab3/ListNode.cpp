#include "ListNode.h"
#include <iostream>
using namespace std;

template <class T>
ListNode<T>::ListNode() : val(0), next(nullptr)
{
}

// Конструктор с параметром данных
template <class T>
ListNode<T>::ListNode(T x) : val(x), next(nullptr)
{
}

// Конструктор с параметром данных и указателем на следующий элемент списка
template <class T>
ListNode<T>::ListNode(T x, ListNode *next) : val(x), next(next)
{
}

class FixedCapacityStack
{
private:
    int *a; // массив, содержащий элементы Стека int n; // количество элементов в Стеке
public:
    // Конструктор: создать пустой динамический массив с размером, равным
    переданному аргументу;
    проинициализировать число элементов в Стеке
    FixedCapacityStack(int capacity);
    // Деструктор: освободить память массива (delete)
    ~FixedCapacityStack();
    // Проверка на пустоту стека
    bool empty const();
    // Проверка на полноту стека
    bool full const();
    // Добавить элемент в стек
    void push(int item);
    // Удалить вершину стека
    int pop();
    // Вернуть значение вершины стека
    int top const();
    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream &operator<<(ostream &os, FixedCapacityStack &st);
}; // FixedCapacityStack

class Stack
{
private:
    ListNode *first; // указатель на вершину Стека int n; // количество элементов в Стеке
public:
    // Конструктор: инициализация пустого Стека Stack();
    // Проверка на пустоту стека
    bool empty const();
    // Вернуть размер стека
    int size();
    // Добавить элемент в стек
    void push(int item);
    // Удалить вершину стека
    int pop();
    // Вернуть значение вершины стека
    int top const();
    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream &operator<<(ostream &os, Stack &st);
}; // Stack


class Queue
{
private:
    ListNode
        ListNode int n;
    *first; // указатель на начало очереди *last; // указатель на конец очереди // количество элементов в очереди
public:
    // Конструктор: инициализация пустой очереди Queue();
    // Проверка на пустоту очереди
    bool empty const();
    // Вернуть размер стека
    int size();
    // Добавить элемент в очередь
    void enqueue(int item);
    // Удалить элемент из очереди
    int dequeue();
    // Вернуть значение первого добавленного элемента в очередь
    int front const();
    // Вернуть значение последнего добавленного элемента в очередь
    int back const();
    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream &operator<<(ostream &os, Queue &q);
}; // Queue

int main()
{
    FixedCapacityStack mystack = new FixedCapacityStack(5);
    for (int i = 1; i <= 5; ++i)
    {
        mystack.push(i);
    }
    // Вывод элементов стека
    std::cout << mystack << std::endl;
    mystack.push(6); // проверка на добавление элемента в полный стек
    // Очищение стека – удаление всех элементов
    while (!mystack.empty())
    {
        mystack.pop();
    }
    std::cout << mystack << std::endl;
    return 0;
}