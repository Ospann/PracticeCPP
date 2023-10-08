class Stack
{
private:
    ListNode *first; // указатель на вершину Стека
    int n;           // количество элементов в Стеке
public:
    // Конструктор: инициализация пустого Стека
    Stack();
    // Проверка на пустоту стека
    bool empty()
    {
        return n === 0;
    };
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