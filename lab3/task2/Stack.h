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

    /**
     * Функция перегрузки оператора вывода для объектов класса Stack.
     * 
     * @template T - Тип элементов в стеке
     * @param {ostream} os - Поток вывода, в который будет записан стек
     * @param {Stack<T>} st - Ссылка на объект класса Stack, который нужно вывести
     * @returns {ostream} - Ссылка на поток вывода с записанным стеком
     * 
     * @description
     * Функция friend перегружает оператор "<<" для класса Stack, позволяя выводить
     * элементы стека в поток вывода (например, на консоль) с помощью стандартного
     * синтаксиса "cout << stack". Это делает возможным более удобный вывод стековых
     * данных без необходимости раскрывать внутренние детали класса Stack.
     */
    friend ostream& operator<<(ostream& os, const Stack<T>& st) {
        ListNode<T>* current = st.first;
        while (current != nullptr) {
            os << current->val << " ";
            current = current->next;
        }
        return os;
    }
};