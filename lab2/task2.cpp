#include <iostream>
using namespace std;

int main()
{
    return 0;
}

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *head = llist;
    DoublyLinkedListNode *temp = new DoublyLinkedListNode(data);
    if (head == NULL)
    {
        return NULL;
    }
    if (data < head->data)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        while (head->next != NULL && head->next->data <= data)
        {
            head = head->next;
        }
        temp->next = head->next;
        if (head->next != NULL)
        {
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
        }
        else
        {
            head->next = temp;
            temp->prev = head;
        }
    }
    return llist;
}