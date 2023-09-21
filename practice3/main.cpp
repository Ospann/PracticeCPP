#include <iostream>
#include <string>
using namespace std;

// class Student
// {
// private:
//     string name;
//     int birthYear;
//     int enrollmentYear;
//     double firstSemesterCost;
//     double physicsGrade;
//     double mathGrade;
//     double informaticsGrade;

// public:
//     Student() : name(""), birthYear(0), enrollmentYear(0), firstSemesterCost(0),
//                 physicsGrade(0), mathGrade(0), informaticsGrade(0) {}

//     Student(const string name, int bYear, int eYear, double semCost,
//             double phys, double math, double info)
//         : name(name), birthYear(bYear), enrollmentYear(eYear),
//           firstSemesterCost(semCost), physicsGrade(phys),
//           mathGrade(math), informaticsGrade(info) {}

//     const string &getName() const
//     {
//         return name;
//     }
// };

// class University
// {
// private:
//     Student students[10];

// public:
//     University()
//     {
//         students[0] = Student("Оспанов А.Р.", 2000, 2021, 5000, 90, 95, 85);
//         students[1] = Student("Исмуханов И.И.", 1999, 2021, 4800, 85, 92, 88);
//         students[2] = Student("Джанайдаров Д.Д.", 2000, 2021, 5000, 90, 95, 85);
//         students[3] = Student("Алмагендиев А.А.", 1999, 2021, 4800, 85, 92, 88);
//         students[4] = Student("Омаров О.О.", 2000, 2021, 5000, 90, 95, 85);
//         students[5] = Student("Караулов К.К.", 1999, 2021, 4800, 85, 92, 88);
//         students[6] = Student("Оспан О.О.", 2000, 2021, 5000, 90, 95, 85);
//         students[7] = Student("Багдаулетов Б.Б.", 1999, 2021, 4800, 85, 92, 88);
//         students[8] = Student("Иманов И.И.", 2000, 2021, 5000, 90, 95, 85);
//         students[9] = Student("Назарбаев Н.Н.", 1999, 2021, 4800, 85, 92, 88);
//     }

//     ~University()
//     {
//     }

//     void print()
//     {
//         int arrSize = *(&students + 1) - students;

//         for (int i = 0; i < arrSize; i++)
//         {
//             cout << "Name: " << students[i].getName() << endl;
//         }
//     }

//     // bubleSort
//     void sortByLastName(Student arr[], int n)
//     {
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = 0; j < n - i - 1; j++)
//             {
//                 if (arr[j] > arr[j + 1])
//                 {
//                     swap(arr[j], arr[j + 1]);
//                 }
//             }
//         }
//     }
// };
class Group
{
private:
    string *student;
    int arrSize;

public:
    Group(string arr[], int size) : student(arr), arrSize(size) {}

    void sortByBubble()
    {
        for (int i = 0; i < arrSize - 1; i++)
        {
            for (int j = 0; j < arrSize - i - 1; j++)
            {
                if (student[j] > student[j + 1])
                {
                    string temp = student[j];
                    student[j] = student[j + 1];
                    student[j + 1] = temp;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < arrSize; i++)
        {
            cout << student[i] << "\n";
        }
    }
};

int main()
{
    string student[] = {"Ospanov A.R.",
                        "Omarov I.E.",
                        "Timurov A.E.",
                        "Ibrayev R.R.",
                        "Bekeshev B.D.",
                        "Rejepov A.R.",
                        "Issayev I.I."};
    int arrSize = sizeof(student) / sizeof(student[0]);

    Group group(student, arrSize);

    group.sortByBubble();
    group.print();

    // University myUniversity;
    // myUniversity.sortByLastName();
    // myUniversity.print();

    return 0;
}
