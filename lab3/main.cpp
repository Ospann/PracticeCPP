#include <iostream>
#include "Stack"
using namespace std;

int main(){
    Stack mystack(5);
    for (int i = 1; i <= 5; ++i)
    {
        mystack.push(i);
    }

    cout << mystack << endl;

    while (!mystack.empty())
    {
        mystack.pop();
    }
    cout << "After delete:" << mystack.empty() << endl;

    return 0;
}