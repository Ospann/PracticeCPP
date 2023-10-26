#include <iostream>
using namespace std;

template <typename T, int Rows, int Cols>
class Matrix
{
public:
    Matrix()
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                data[i][j] = T();
            }
        }
    }

    Matrix(T initValue)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                data[i][j] = initValue;
            }
        }
    }

    T &operator()(int row, int col)
    {
        if (row < 0 || row >= Rows || col < 0 || col >= Cols)
        {
            throw out_of_range("Matrix indices are out of range");
        }
        return data[row][col];
    }

    const T &operator()(int row, int col) const
    {
        if (row < 0 || row >= Rows || col < 0 || col >= Cols)
        {
            throw out_of_range("Matrix indices are out of range");
        }
        return data[row][col];
    }

    void print()
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                cout << data[i][j] << ' ';
            }
            cout << endl;
        }
    }

private:
    T data[Rows][Cols];
};

int main()
{
    try
    {
        // Создаем матрицу 3x3 с элементами типа double
        Matrix<double, 3, 3> matrix;

        // Заполняем матрицу
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix(i, j) = (i + 1) * (j + 1);
            }
        }

        // Выводим матрицу
        matrix.print();

        // Попытка доступа к элементу за пределами матрицы
        double value = matrix(5, 2); // Вызовет исключение
    }
    catch (const out_of_range &e)
    {
        cerr << "  Ошибочка: " << e.what() << endl;
    }

    return 0;
}
