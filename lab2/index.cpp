#include <iostream>
using namespace std;

/**
 * Struct for store val and val type
 * store link to next list
 */
template <typename T>
struct ListNode
{
    T val;
    ListNode *next;
    ListNode(T x) : val(x), next(NULL) {}
};

template <typename T>
class MyLinkedList
{
private:
    ListNode<T> *head;

public:
    MyLinkedList() : head(NULL) {}

    /**
     * Add val to start position of list
     */
    void addAtHead(T val)
    {
        ListNode<T> *newNode = new ListNode<T>(val);
        newNode->next = head;
        head = newNode;
    }

    /**
     * Just output list
     */
    void print()
    {
        ListNode<T> *current = head;
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    /**
     * Change position of list items
     */
    void reverse()
    {
        //создал лист для реверса
        ListNode<T> *prev = NULL;
        //создал listnode и назначил head
        ListNode<T> *current = head;
        while (current)
        {
            
            ListNode<T> *nextNode = current->next;
            //приравниваю next к null а дальше к предудущему элементу
            current->next = prev;
            // перезаписываю null на нынешний элемент
            prev = current;
            // current присваевая nextNode
            current = nextNode;
        }

        //в конце перезаписываю head на prev
        head = prev;
    }
};

int main()
{
    MyLinkedList<int> intList;

    intList.addAtHead(1);
    intList.addAtHead(2);
    intList.addAtHead(3);
    intList.print();

    intList.reverse();
    intList.print();

    MyLinkedList<double> doubleList;

    doubleList.addAtHead(1.5);
    doubleList.print();

    doubleList.reverse();
    doubleList.print();

    return 0;
}
