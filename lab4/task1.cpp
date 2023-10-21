#include <iostream>
#include <string>
using namespace std;

/**
 * Рекурсивная функция для вставки символов '*' между символами в строке.
 *
 * @param s - строка, в которой происходит вставка
 * @param index - текущий индекс символа в строке
 */
void addStart(string &s, int index)
{
    // Базовый случай: если индекс достиг конца строки, завершаем рекурсию.
    if (index == s.length() - 1)
    {
        return;
    }

    // Вставляем символ '*' после текущего символа.
    s.insert(index + 1, "*");

    // Рекурсивно вызываем функцию для следующего символа.
    addStart(s, index + 2);
}

int main()
{
    string input;
    cout << "Введите ваш текст: ";
    cin >> input;

    addStart(input, 0);

    cout << input << endl;

    return 0;
}
