#include <bits/stdc++.h>

using namespace std;

class Complex
{
private:
    double realPart;
    double complexPart;

public:
    Complex(void) { realPart = complexPart = 0; }

    Complex(double realPart, double complexPart) : realPart(realPart), complexPart(complexPart) {}

    Complex(Complex &object) : realPart(object.realPart), complexPart(object.complexPart) {}

    void set(double realPart, double complexPart)
    {
        this->realPart = realPart;
        this->complexPart = complexPart;
    }

    double getReal(void) { return this->realPart; }
    double getComplex(void) { return this->complexPart; }

    friend ostream &operator<<(ostream &, const Complex &);
    friend Complex operator~(const Complex &);
    friend Complex operator+(const Complex &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator*(const Complex &, const Complex &);
    friend Complex operator/(const Complex &, const Complex &);
    Complex operator=(const Complex &);
};

ostream &operator<<(ostream &out, const Complex &object)
{
    out << object.realPart << " + " << object.complexPart << "i";
    return out;
}

Complex operator~(const Complex &object)
{
    Complex result(object.realPart, -object.complexPart);
    return result;
}

Complex operator+(const Complex &object_1, const Complex &object_2)
{
    Complex result(object_1.realPart + object_2.realPart, object_1.complexPart + object_2.complexPart);
    return result;
}

Complex operator-(const Complex &object_1, const Complex &object_2)
{
    Complex result(object_1.realPart - object_2.realPart, object_1.complexPart - object_2.complexPart);
    return result;
}

Complex operator*(const Complex &object_1, const Complex &object_2)
{
    double a = object_1.realPart, b = object_1.complexPart, c = object_2.realPart, d = object_2.complexPart;
    Complex result(a * c - b * d, a * d + b * c);
    return result;
}

Complex operator/(const Complex &object_1, const Complex &object_2)
{
    Complex result = object_1 * ~object_2;
    double denominator = (object_2 * ~object_2).realPart;
    result.realPart /= denominator;
    result.complexPart /= denominator;
    return result;
}

Complex Complex::operator=(const Complex &object)
{
    this->realPart = object.realPart;
    this->complexPart = object.complexPart;
    return *this;
}

int main(void)
{
    Complex cmplx1, cmplx2;
    cmplx1.set(2, 5);
    cout << cmplx1 << '\n';
    cmplx2.set(8, 9);
    cout << cmplx2 << '\n';

    cmplx1 = cmplx2;

    cout << (cmplx1 + cmplx2) << '\n';
    cout << (cmplx1 - cmplx2) << '\n';
    cout << (cmplx1 * cmplx2) << '\n';
    cout << (cmplx1 / cmplx2) << '\n';
    return 0;
}