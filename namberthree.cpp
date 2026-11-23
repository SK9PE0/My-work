#include <iostream>
using namespace std;

// Функция возвращает максимальное из двух целых чисел
int maxOfTwo(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int x, y;

    cout << "Введите первое число: ";
    cin >> x;
    cout << "Введите второе число: ";
    cin >> y;

    cout << "Максимальное число: " << maxOfTwo(x, y) << endl;

    return 0;
}