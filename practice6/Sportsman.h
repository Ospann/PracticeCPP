#include <iostream>
#include <string>
using namespace std;

class Sportsman : public Human
{
private:
    string sportName;
    int numberOfMedals;
    int numberOfYears;

public:
    Sportsman(string last, string first, string pat, char gen, int year, string addr, string sport, int medals, int years)
        : Human(last, first, pat, gen, year, addr), sportName(sport), numberOfMedals(medals), numberOfYears(years)
    {
    }

    void displayInfo()
    {
        cout << "Sportsman Information:" << endl;
        cout << "Name: " << getLastName() << " " << getFirstName() << " " << getPatronymic() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Birth Year: " << getBirthYear() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Sport: " << sportName << endl;
        cout << "Number of Medals: " << numberOfMedals << endl;
        cout << "Number of Years: " << numberOfYears << endl;
    }

    void winMedal()
    {
        numberOfMedals++;
    }

    void spendYear()
    {
        numberOfYears++;
    }

    void setSportName(string sport)
    {
        sportName = sport;
    }

    string getSportName() const
    {
        return sportName;
    }

    int getNumberOfMedals() const
    {
        return numberOfMedals;
    }

    int getNumberOfYears() const
    {
        return numberOfYears;
    }
};
