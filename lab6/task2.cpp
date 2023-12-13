#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    // Инициализация вектора для хранения исходных идентификаторов
    vector<int> ids;
    int id, newId;

    // Считывание исходных идентификаторов из строки ввода
    string line;
    getline(cin, line);
    istringstream is(line);
    while (is >> id)
    {
        ids.push_back(id);
    }

    // Считывание нового идентификатора
    cin.clear();
    cin >> newId;

    // Инициализация переменных для бинарного поиска
    int insertIndex = 0;
    int endIndex = ids.size() - 1;
    int middle;

    // Бинарный поиск для определения места вставки нового идентификатора
    while (insertIndex <= endIndex)
    {
        middle = (insertIndex + endIndex) / 2;

        if (ids[middle] == newId)
        {
            // Если новый идентификатор уже присутствует, завершаем поиск
            break;
        }
        else if (ids[middle] < newId)
        {
            // Если новый идентификатор больше, ищем в правой половине
            insertIndex = middle + 1;
        }
        else
        {
            // Если новый идентификатор меньше, ищем в левой половине
            endIndex = middle - 1;
        }
    }

    // Вставка нового идентификатора в найденное место
    ids.insert(ids.begin() + insertIndex, newId);

    // Вывод отсортированного списка идентификаторов
    for (const auto &id : ids)
    {
        cout << id << " ";
    }

    return 0;
}
