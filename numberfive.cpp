#include <iostream>
#include <cmath>
using namespace std;

class Ring
{
private:
    double outerRadius;  // внешний радиус
    double innerRadius;  // внутренний радиус

public:
    // Конструктор по умолчанию
    Ring() : outerRadius(2.0), innerRadius(1.0) {}

    // Конструктор с параметрами
    Ring(double outer, double inner)
    {
        setRadii(outer, inner);
    }

    // Установка радиусов (с проверкой: 0 < inner < outer)
    void setRadii(double outer, double inner)
    {
        if (inner > 0 && outer > inner)
        {
            outerRadius = outer;
            innerRadius = inner;
        }
        else
        {
            cout << "Ошибка: должно быть 0 < внутренний < внешний. "
                 << "Установлены значения по умолчанию (2 и 1)" << endl;
            outerRadius = 2.0;
            innerRadius = 1.0;
        }
    }

    double getOuterRadius() const { return outerRadius; }
    double getInnerRadius() const { return innerRadius; }

    // Ширина кольца
    double width() const
    {
        return outerRadius - innerRadius;
    }

    // Площадь кольца: pi * (R^2 - r^2)
    double area() const
    {
        return M_PI * (outerRadius * outerRadius - innerRadius * innerRadius);
    }

    // Суммарная длина внешней и внутренней окружностей
    double perimeter() const
    {
        return 2 * M_PI * (outerRadius + innerRadius);
    }

    // Вывод информации о кольце
    void print() const
    {
        cout << "Внешний радиус: " << outerRadius << endl;
        cout << "Внутренний радиус: " << innerRadius << endl;
        cout << "Ширина кольца: " << width() << endl;
        cout << "Площадь: " << area() << endl;
        cout << "Сумма длин окружностей: " << perimeter() << endl;
    }
};

int main()
{
    // Тест 1: конструктор по умолчанию
    cout << "Кольцо по умолчанию:" << endl;
    Ring r1;
    r1.print();

    // Тест 2: радиусы вводятся с клавиатуры
    double outer, inner;
    cout << "\nВведите внешний радиус: ";
    cin >> outer;
    cout << "Введите внутренний радиус: ";
    cin >> inner;
    Ring r2(outer, inner);
    cout << "\nВаше кольцо:" << endl;
    r2.print();

    // Тест 3: изменение радиусов
    r2.setRadii(10, 6);
    cout << "\nПосле изменения радиусов на 10 и 6:" << endl;
    r2.print();

    return 0;
}