

template <typename T>
class Stack
{
private:
    T *a;         // массив, содержащий элементы Стека
    int n;        // количество элементов в Стеке
    int capacity; // максимальная вместимость стека
public:
    // Конструктор: создать пустой динамический массив с размером, равным capacity
    Stack(int capacity)
    {
        this->capacity = capacity;
        a = new T[capacity];
        n = 0; // Начальное количество элементов в стеке равно 0
    };

    // Деструктор: освободить память массива (delete)
    ~Stack()
    {
        delete[] a;
    }

    // Проверка на пустоту стека
    bool empty()
    {
        return n == 0;
    }

    // Проверка на полноту стека
    bool full()
    {
        return n == capacity;
    }

    // Добавить элемент в стек
    void push(int item)
    {
        if (full())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            a[n++] = item;
        }
    }

    void resize(int new_capacity)
    {
        //проверочка
        if (new_capacity <= 0)
        {
            cout << "Invalid capacity" << endl;
            return;
        }

        T *new_a = new T[new_capacity];

        // Копируем элементы из старого массива в новый
        for (int i = 0; i < n; ++i)
        {
            new_a[i] = a[i];
        }

        // Освобождаем старый массив
        delete[] a;

        // Обновляем указатель на новый массив и вместимость
        a = new_a;
        capacity = new_capacity;
    }

    // Удалить вершину стека
    int pop()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return a[--n];
    }

    // Вернуть значение вершины стека
    int top()
    {
        if (empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return a[n - 1];
    }

    // Перегрузка оператора << для вывода элементов стека через cout
    friend ostream &operator<<(ostream &os, Stack &st)
    {
        for (int i = 0; i < st.n; ++i)
        {
            os << st.a[i] << " ";
        }
        return os;
    }
};