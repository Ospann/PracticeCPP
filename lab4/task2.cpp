#include <iostream>

using namespace std;

/**
 * Функция для нахождения наибольшего общего делителя (НОД) двух чисел.
 *
 * @param a - первое число
 * @param b - второе число
 * @return НОД(a, b)
 */
int gcd(int a, int b)
{
    while (b != 0)
    {
        // Пока второе число не станет равным нулю, находим остаток от деления a на b
        // и меняем значения a и b на b и остаток соответственно.
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Когда второе число станет равным нулю, первое число (a) будет НОД(a, b).
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int result = gcd(a, b);
    cout << result << endl;
    return 0;
}
