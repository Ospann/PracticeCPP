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

    void Add(T val)
    {
        ListNode<T> *newNode = new ListNode<T>(val);

        if (!head || val < head->val)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        ListNode<T> *current = head;
        while (current->next && current->next->val < val)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
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
};

int main()
{
    MyLinkedList<int> intList;

    intList.Add(1);
    intList.Add(2);
    intList.Add(4);
    intList.Add(3);

    intList.print();

    return 0;
}
