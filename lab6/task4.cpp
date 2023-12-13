#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Функция calculateAverage вычисляет среднее значение вектора
double calculateAverage(const vector<int> &vec)
{
    if (vec.empty())
    {
        return 0.0;
    }

    int sum = 0;
    for (int value : vec)
    {
        sum += value;
    }

    return static_cast<double>(sum) / vec.size();
}

// Функция compareVectors используется для сравнения векторов по их среднему значению
bool compareVectors(const vector<int> &a, const vector<int> &b)
{
    return calculateAverage(a) < calculateAverage(b);
}

int main()
{
    // Ввод количества студентов
    int n;
    cin >> n;
    // используется для очистки буфера ввода (input buffer) после считывания числа или строки с помощью cin.
    cin.ignore();

    // Инициализация вектора векторов для хранения оценок студентов
    vector<vector<int>> grades;

    // Заполнение вектора векторов оценками
    for (int i = 0; i < n; ++i)
    {
        // Считывание строки с оценками
        string line;
        getline(cin, line);
        istringstream iss(line);

        // Инициализация вектора для текущих оценок
        vector<int> currentGrades;
        int grade;

        // Считывание оценок из строки
        while (iss >> grade)
        {
            currentGrades.push_back(grade);
        }

        // Добавление вектора с оценками текущего студента в общий вектор
        grades.push_back(currentGrades);
    }

    // Сортировка вектора векторов по среднему значению
    sort(grades.begin(), grades.end(), compareVectors);

    // Вывод отсортированного массива
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < grades[i].size(); ++j)
        {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
