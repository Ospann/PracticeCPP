class MyQueue
{
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {}

    /**
     * Добавляет элемент в конец очереди.
     * @param x - Элемент, который нужно добавить.
     */
    void push(int x)
    {
        inStack.push(x);
    }

    /**
     * Извлекает и удаляет элемент из начала очереди.
     * @return Извлеченный элемент.
     */
    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    /**
     * Возвращает элемент из начала очереди без его удаления.
     * @return Элемент из начала очереди.
     */
    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    /**
     * Проверяет, пуста ли очередь.
     * @return true, если очередь пуста, в противном случае - false.
     */
    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};
