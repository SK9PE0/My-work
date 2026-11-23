#include <iostream>
using namespace std;

class X
{
public:
    virtual double A(double x) { return x * x; }
    double B(double x) { return A(x) / 2; }
};

class Y : public X
{
public:
    double A(double x) override { return x * x * x; }
};

int main()
{
    Y y;
    cout << y.B(3) << endl;
    return 0;
}