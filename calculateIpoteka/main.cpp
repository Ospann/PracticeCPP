#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void calcualtion(int sum, int years, double percent)
{
    double monthlyInterestRate = (percent / 100) / 12;

    // Общее количество месяцев
    int totalMonths = years * 12;

    // Ежемесячный платеж
    /*
     *
     *
     *
     */
    double monthlyPayment = (sum * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalMonths));

    // Общая сумма выплат
    double totalPayment = monthlyPayment * totalMonths;
    double overpayment = totalPayment - sum;

    cout << fixed; // Устанавливаем фиксированный формат вывода
    cout << setprecision(2);
    cout << "Ежемесячный платеж: " << monthlyPayment << " тенге" << endl;
    cout << "Общая сумма выплат: " << totalPayment << " тенге" << endl;
    cout << "Переплата: " << overpayment << " тенге" << endl;
}

int main()
{
    int sum, years;
    double percent;

    cout << "Введите сумму стоимости квартиры: ";
    cin >> sum;

    cout << "Введите на сколько лет планируете взять ипотеку: ";
    cin >> years;

    cout << "Введите процентную годовую ставку: ";
    cin >> percent;

    calcualtion(sum, years, percent);

    return 0;
}
