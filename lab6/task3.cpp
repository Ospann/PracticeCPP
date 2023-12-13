#include <iostream>
#include <vector>

using namespace std;

// Функция countingSort выполняет сортировку списка list2 по частоте встречаемости элементов из list1
void countingSort(vector<int> &list1, const vector<int> &list2, int maxValue)
{
    // Массив частот для элементов из list1
    vector<int> freqArray(maxValue + 1, 0);

    // Дополнительные векторы для хранения результатов сортировки
    vector<int> extraElements;
    vector<int> sortedList2;

    // Подсчет частот элементов из list1
    for (int num : list1)
    {
        freqArray[num]++;
    }

    // Формирование отсортированного списка list2
    for (int num : list2)
    {
        for (int j = 0; j < freqArray[num]; j++)
        {
            sortedList2.push_back(num);
        }
        freqArray[num] = 0;
    }

    // Формирование списка дополнительных элементов
    for (int i = 0; i <= maxValue; i++)
    {
        for (int j = 0; j < freqArray[i]; j++)
        {
            extraElements.push_back(i);
        }
    }

    // Вывод отсортированного списка list2
    for (int num : sortedList2)
    {
        cout << num << " ";
    }

    // Вывод списка дополнительных элементов
    for (int num : extraElements)
    {
        cout << num << " ";
    }
}

int main()
{
    // Ввод размеров списков
    int N1, N2, maxValue = 0;
    cin >> N1 >> N2;

    // Инициализация списков
    vector<int> list1(N1);
    vector<int> list2(N2);

    // Заполнение первого списка и нахождение максимального значения
    for (int i = 0; i < N1; ++i)
    {
        cin >> list1[i];
        maxValue = max(maxValue, list1[i]);
    }

    // Заполнение второго списка
    for (int i = 0; i < N2; ++i)
    {
        cin >> list2[i];
    }

    // Вызов функции countingSort для выполнения сортировки
    countingSort(list1, list2, maxValue);

    return 0;
}
