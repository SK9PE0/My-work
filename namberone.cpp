#include <iostream>
#include <clocale>
using namespace std;

// Ввод массива по строкам с подсказкой
void inputArray(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            cout << "Введите элемент [строка " << i + 1 
                 << ", столбец " << j + 1 << "]: ";
            cin >> a[i][j];
        }
}

// Вывод массива на экран
void printArray(int** a, int rows, int cols)
{
    cout << "\nЗаполненный массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// Сумма элементов по столбцам
void calcColumnSums(int** a, int rows, int cols, int* sums)
{
    for (int j = 0; j < cols; j++)
    {
        sums[j] = 0;
        for (int i = 0; i < rows; i++)
            sums[j] += a[i][j];
    }
}

// Вывод сумм
void printSums(int* sums, int cols)
{
    cout << "\nСуммы элементов по столбцам:\n";
    for (int j = 0; j < cols; j++)
        cout << "Столбец " << j + 1 << ": " << sums[j] << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int rows, cols;
    cout << "Количество строк: ";
    cin >> rows;
    cout << "Количество столбцов: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0)
    {
        cout << "Размеры должны быть положительными!" << endl;
        return 1;
    }

    // Выделение памяти
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
    int* sums = new int[cols];

    inputArray(arr, rows, cols);
    printArray(arr, rows, cols);
    calcColumnSums(arr, rows, cols, sums);
    printSums(sums, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;
    delete[] sums;

    return 0;
}
