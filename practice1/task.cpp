// 13 variant

#include <iostream>

using namespace std;

int main()
{
    int number, sum = 0;

    cout << "Enter your number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Invalid Format" << endl;
        return 1;
    }

    while (number != 0)
    {
        int digit = number % 10;
        sum += digit;
        number /= 10;
        cout << "sum:" << sum << endl;
        cout << "number:" << number << endl;
    }

    cout << "Summ:" << sum << endl;

    return 0;
}
