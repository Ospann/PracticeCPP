#include <iostream>

using namespace std;

// global array
int memo[31];

/**
 * Рекурсивная функция для вычисления числа Фибоначчи.
 *
 * @param n - индекс числа Фибоначчи
 * @return - значение числа Фибоначчи
 */
int fibonacci(int n)
{
    // Если значение уже было рассчитано, возвращаем его из массива мемоизации.
    if (memo[n] != -1)
    {
        return memo[n];
    }

    // Базовый случай : Фибоначчи для 0 и 1 уже известны.
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Рекурсивно вычисляем Фибоначчи и сохраняем результат в массиве мемоизации.
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    // Инициализируем массив мемоизации.
    for (int i = 0; i <= 30; i++)
    {
        memo[i] = -1;
    }

    // Вычисляем значение числа Фибоначчи и выводим его.
    int result = fibonacci(n);
    cout << result << endl;
    return 0;
}
