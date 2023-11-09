#include <iostream>
using namespace std;

template <typename T, int Rows, int Cols>
class Matrix
{

private:
    T data[Rows][Cols];

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
            throw out_of_range("Матрица выходит за пределы");
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
};

int main()
{
    try
    {
        Matrix<double, 4, 4> matrix;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                matrix(i, j) = (i + 1) * (j + 1);
            }
        }

        matrix.print();

        double value = matrix(5, 2);
    }
    catch (const out_of_range &e)
    {
        cerr << "  Ошибочка: " << e.what() << endl;
    }

    return 0;
}
