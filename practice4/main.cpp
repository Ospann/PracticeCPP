#include <iostream>
using namespace std;

class Complex
{
public:
    // Конструктор класса
    Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

    // Метод для сложения комплексных чисел
    Complex Add(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Метод для вычитания комплексных чисел
    Complex Sub(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Метод для умножения комплексных чисел
    Complex Mul(const Complex &other) const
    {
        double newReal = (real * other.real) - (imag * other.imag);
        double newImag = (real * other.imag) + (imag * other.real);
        return Complex(newReal, newImag);
    }

    // Метод для деления комплексных чисел
    Complex Div(const Complex &other) const
    {
        double divisor = (other.real * other.real) + (other.imag * other.imag);
        double newReal = ((real * other.real) + (imag * other.imag)) / divisor;
        double newImag = ((imag * other.real) - (real * other.imag)) / divisor;
        return Complex(newReal, newImag);
    }

    // Метод для вывода комплексного числа
    void Print() const
    {
        cout << "(" << real << ", " << imag << ")" << endl;
    }

private:
    double real;
    double imag;
};

int main()
{
    Complex z1(2.0, 3.0);
    Complex z2(1.0, 2.0);

    Complex sum = z1.Add(z2);
    Complex diff = z1.Sub(z2);
    Complex product = z1.Mul(z2);
    Complex quotient = z1.Div(z2);

    cout << "Сумма: ";
    sum.Print();

    cout << "Разность: ";
    diff.Print();

    cout << "Произведение: ";
    product.Print();

    cout << "Частное: ";
    quotient.Print();

    return 0;
}
