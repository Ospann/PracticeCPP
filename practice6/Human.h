#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    virtual void displayInfo() = 0;
    // Конструктор по умолчанию
    Human()
    {
        lastName = "";
        firstName = "";
        patronymic = "";
        gender = ' ';
        birthYear = 0;
        address = "";
    }

    // Конструктор с параметрами
    Human(string last, string first, string pat, char gen, int year, string addr)
    {
        lastName = last;
        firstName = first;
        patronymic = pat;
        gender = gen;
        birthYear = year;
        address = addr;
    }

    // Деструктор
    ~Human()
    {
        // Пока не нужно освобождать какие-либо ресурсы
    }

    // Методы для установки и получения значений полей
    void setLastName(string last)
    {
        lastName = last;
    }

    string getLastName() const
    {
        return lastName;
    }

    void setFirstName(string first)
    {
        firstName = first;
    }

    string getFirstName() const
    {
        return firstName;
    }

    void setPatronymic(string pat)
    {
        patronymic = pat;
    }

    string getPatronymic() const
    {
        return patronymic;
    }

    void setGender(char gen)
    {
        gender = gen;
    }

    char getGender() const
    {
        return gender;
    }

    void setBirthYear(int year)
    {
        birthYear = year;
    }

    int getBirthYear() const
    {
        return birthYear;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    string getAddress() const
    {
        return address;
    }

private:
    string lastName;
    string firstName;
    string patronymic;
    char gender;
    int birthYear;
    string address;
};
