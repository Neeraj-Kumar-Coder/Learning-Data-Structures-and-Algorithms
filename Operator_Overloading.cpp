#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
    double real;
    double complx;
    Complex(void) {}

    Complex(const double &r, const double &c)
    {
        real = r;
        complx = c;
    }

    double getMod(void)
    {
        return sqrt(real * real + complx * complx);
    }

    Complex conjugate(void)
    {
        Complex z;
        z.real = real;
        z.complx = -complx;
        return z;
    }

    friend ostream &operator<<(ostream &, Complex);
    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);
    friend Complex operator*(Complex, Complex);
    friend Complex operator/(Complex, Complex);
    friend bool operator==(Complex, Complex);
    friend bool operator!=(Complex, Complex);
};

ostream &operator<<(ostream &out, Complex c)
{
    out << c.real << " + " << c.complx << "i";
    return out;
}

Complex operator+(Complex a, Complex b)
{
    int r = a.real + b.real;
    int c = a.complx + b.complx;
    Complex d(r, c);
    return d;
}

Complex operator-(Complex a, Complex b)
{
    int r = a.real - b.real;
    int c = a.complx - b.complx;
    Complex d(r, c);
    return d;
}

Complex operator*(Complex a, Complex b)
{
    Complex z;
    z.real = a.real * b.real - a.complx * b.complx;
    z.complx = a.real * b.complx + a.complx * b.real;
    return z;
}

Complex operator/(Complex a, Complex b)
{
    Complex z;
    z = a * b.conjugate();
    z.real /= b.real * b.real + b.complx * b.complx;
    z.complx /= b.real * b.real + b.complx * b.complx;
    return z;
}

bool operator==(Complex a, Complex b)
{
    return a.real == b.real && a.complx == b.complx;
}

bool operator!=(Complex a, Complex b)
{
    return !(a == b);
}

int main(void)
{
    Complex a(3, 5);
    Complex b(5, 3);
    Complex z1 = a + b;
    Complex z2 = a - b;
    Complex z3 = a * b;
    Complex z4 = a / b;

    cout << a << " Mod value = " << a.getMod() << '\n';
    cout << b << " Mod value = " << b.getMod() << '\n';
    cout << z1 << " Mod value = " << z1.getMod() << '\n';
    cout << z2 << " Mod value = " << z2.getMod() << '\n';
    cout << z3 << " Mod value = " << z3.getMod() << '\n';
    cout << z4 << " Mod value = " << z4.getMod() << '\n';

    cout << (a == b) << '\n';
    cout << (a != b) << '\n';
    return 0;
}