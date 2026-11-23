#include <iostream>
#include <cmath>
using namespace std;

//V = pi * r^2 * h
double cylinderVolume(double radius, double height)
{
    return M_PI * radius * radius * height;
}

int main()
{
    double r, h;

    cout << "Введите радиус цилиндра: ";
    cin >> r;
    cout << "Введите высоту цилиндра: ";
    cin >> h;

    if (r < 0 || h < 0)
    {
        cout << "Радиус и высота не могут быть отрицательными!" << endl;
        return 1;
    }

    cout << "Объем цилиндра: " << cylinderVolume(r, h) << endl;

    return 0;
}