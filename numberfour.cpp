#include <iostream>
#include <cmath>
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle() : radius(1.0) {}

    Circle(double r)
    {
        setRadius(r);
    }

    void setRadius(double r)
    {
        if (r > 0)
            radius = r;
        else
        {
            cout << "Радиус должен быть положительным, установлено значение 1" << endl;
            radius = 1.0;
        }
    }

    double getRadius() const
    {
        return radius;
    }

    double diameter() const
    {
        return 2 * radius;
    }

    double circumference() const
    {
        return 2 * M_PI * radius;
    }

    double area() const
    {
        return M_PI * radius * radius;
    }

    void print() const
    {
        cout << "Радиус: " << radius << endl;
        cout << "Диаметр: " << diameter() << endl;
        cout << "Длина окружности: " << circumference() << endl;
        cout << "Площадь: " << area() << endl;
    }
};

int main()
{
    cout << "Круг по умолчанию:" << endl;
    Circle c1;
    c1.print();

    double r;
    cout << "\nВведите радиус круга: ";
    cin >> r;
    Circle c2(r);
    cout << "\nВаш круг:" << endl;
    c2.print();

    c2.setRadius(10);
    cout << "\nПосле изменения радиуса на 10:" << endl;
    c2.print();

    return 0;
}