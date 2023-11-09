#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void calculation(int sum, int years, double percent, int downPayment)
{
    sum -= downPayment;

    if (sum <= 0)
    {
        cout << "Сумма кредита после вычета первоначального взноса должна быть больше нуля." << endl;
        return;
    }

    // Вычисление месяцного процента
    double monthlyInterestRate = (percent / 100) / 12;
    // все колво месяцев
    int totalMonths = years * 12;
    int totalSum = sum * monthlyInterestRate;

    double monthlyPayment = totalSum / (1 - pow(1 + monthlyInterestRate, -totalMonths));

    double totalPayment = monthlyPayment * totalMonths;
    double overpayment = totalPayment - sum;

    cout << fixed;
    cout << setprecision(2);
    cout << "Ежемесячный платеж: " << monthlyPayment << " тенге" << endl;
    cout << "Общая сумма выплат: " << totalPayment << " тенге" << endl;
    cout << "Переплата: " << overpayment << " тенге" << endl;
}

int main()
{
    int sum, years, downPayment;
    double percent;

    cout << "Введите сумму стоимости квартиры: ";
    cin >> sum;

    cout << "Введите первоначальный взнос: ";
    cin >> downPayment;

    cout << "Введите на сколько лет планируете взять ипотеку: ";
    cin >> years;

    cout << "Введите процентную годовую ставку: ";
    cin >> percent;

    calculation(sum, years, percent, downPayment);

    return 0;
}
