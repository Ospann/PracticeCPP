#include <iostream>
#include <vector>

using namespace std;

// Функция possible проверяет, возможно ли украсть все золотые слитки за H часов со скоростью K
bool possible(const vector<int> &bags, int H, int K)
{
    long long hours_needed = 0;
    for (int i = 0; i < bags.size(); ++i)
    {
        // Рассчитываем, сколько часов потребуется для кражи слитков из текущего мешка со скоростью K
        hours_needed += (bags[i] + K - 1) / K; // округление вверх
    }
    // Возвращаем true, если общее количество часов не превышает H
    return hours_needed <= H;
}

int main()
{
    // Ввод количества мешков и времени отсутствия шерифа
    int N, H;
    cin >> N >> H;

    // Инициализация переменной для хранения максимального количества слитков в одном мешке
    int max_slitkov = 0;

    // Инициализация вектора для хранения количества слитков в каждом мешке
    vector<int> bags(N);

    // Считывание количества слитков в каждом мешке и нахождение максимального значения
    for (int i = 0; i < N; ++i)
    {
        cin >> bags[i];
        max_slitkov = max(max_slitkov, bags[i]);
    }

    // Инициализация границ для бинарного поиска
    int left = 1, right = max_slitkov;

    // Бинарный поиск минимальной скорости K, при которой можно украсть все слитки за H часов
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (possible(bags, H, mid))
        {
            // Если возможно, уменьшаем диапазон поиска влево
            right = mid;
        }
        else
        {
            // Если невозможно, увеличиваем диапазон поиска вправо
            left = mid + 1;
        }
    }

    // Вывод минимальной скорости K
    cout << left << endl;

    return 0;
}
