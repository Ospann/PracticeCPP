#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> mystack;

    for (int i = 1; i <= 5; ++i) {
        mystack.push(i);
    }

    // Вывод элементов стека
    cout << "Stack elements: " << mystack << endl;

    // Очищение стека – удаление всех элементов
    while (!mystack.empty()) {
        mystack.pop();
    }

    cout << "After delete: " << mystack.empty() << endl;

    return 0;
}