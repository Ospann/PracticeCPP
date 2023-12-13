#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Ввод количества задач (m) и общего числа задач (n)
    int m, n;
    cin >> m >> n;

    // Создание вектора пар, где первый элемент пары - оценка задачи, второй - её номер
    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; ++i)
    {
        int score;
        cin >> score;
        tasks.push_back({score, i + 1});
    }

    // Сортировка задач по оценкам в порядке возрастания
    sort(tasks.begin(), tasks.end());

    // Инициализация указателей на начало и конец вектора
    int left = 0, right = n - 1;

    // Поиск пары задач, сумма оценок которых равна целевой оценке m
    while (left < right)
    {
        int currentSum = tasks[left].first + tasks[right].first;
        if (currentSum == m)
        {
            // Вывод пары задач и завершение программы
            cout << tasks[left].second << " " << tasks[right].second << endl;
            return 0;
        }
        else if (currentSum < m)
        {
            // Если сумма меньше m, увеличиваем левый указатель
            left++;
        }
        else
        {
            // Если сумма больше m, уменьшаем правый указатель
            right--;
        }
    }

    // Если программа дошла до этой точки, значит, не найдена пара задач
    cerr << "Ошибочка!" << endl;

    // Возвращаем код ошибки
    return 1;
}
