#include <iostream>
#include "ListNode.h"
using namespace std;

template <typename T>
class Stack {
private:
    ListNode<T>* first; // указатель на вершину Стека
    int n;              // количество элементов в Стеке

public:
    // Конструктор: инициализация пустого Стека
    Stack() : first(nullptr), n(0) {}

    // Проверка на пустоту стека
    bool empty() const {
        return n == 0;
    }

    // Вернуть размер стека
    int size() const {
        return n;
    }

    // Добавить элемент в стек
    void push(const T& item) {
        ListNode<T>* newNode = new ListNode<T>(item);
        newNode->next = first;
        first = newNode;
        n++;
    }

    // Удалить вершину стека
    T pop() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        T value = first->val;
        ListNode<T>* temp = first;
        first = first->next;
        delete temp;
        n--;
        return value;
    }

    // Вернуть значение вершины стека
    T top() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return first->val;
    }

    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream& operator<<(ostream& os, const Stack<T>& st) {
        ListNode<T>* current = st.first;
        while (current != nullptr) {
            os << current->val << " ";
            current = current->next;
        }
        return os;
    }
};