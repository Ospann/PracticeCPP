#include <iostream>
using namespace std;

/**
 * Struct for store val and val type
 * store link to next list
 */
template <typename T>
struct Node
{
    T val;
    Node *next;
    Node *prev;
    Node(T x) : val(x), next(NULL), prev(NULL) {}
};

template <typename T>
class MyLinkedList
{
private:
    Node<T> *head;

public:
    MyLinkedList() : head(NULL) {}

    void Add(T val)
    {
        Node<T> *newList = new Node<T>(val);

        /*
         * проверочка не равен ли head null и если первое значение больше
         * то делаем что некст это нынешний head и переназначаем head на наш
         */
        if (!head || val < head->val )
        {
            newList->next = head;
            head = newList;
            return;
        }

        // создал новый узел который изначально равен head
        Node<T> *el = head;

        /*
         * Если значение след элемента меньше чем val, то заменяем el на след элемент
         * цикл будет идти пока мы не найдем элемент больше чем наше значение внутри листа
         */
        while (el->next && el->next->val < val)
        {
            el = el->next;
        }

        // Вставляем новый узел после el
        newList->next = el->next;
        el->next = newList;
    }

    /**
     * Just output list
     */
    void print()
    {
        Node<T> *current = head;
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    MyLinkedList<int> intList;

    intList.Add(1);
    intList.Add(2);
    intList.Add(6);
    intList.Add(3);

    intList.print();

    return 0;
}
