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
        Node<T> *newNode = new Node<T>(val);

        // Если список пустой, новый элемент становится головным элементом
        if (!head)
        {
            head = newNode;
            return;
        }

        // Если новый элемент меньше или равен головному элементу,
        // он становится новым головным элементом
        if (val <= head->val)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node<T> *current = head;

        // Поиск правильной позиции для вставки нового элемента
        while (current->next && val > current->next->val)
        {
            current = current->next;
        }

        // Вставка нового элемента после текущего элемента
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next)
        {
            current->next->prev = newNode;
        }

        current->next = newNode;
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
