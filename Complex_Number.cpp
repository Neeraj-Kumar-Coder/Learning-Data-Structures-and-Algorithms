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
    Complex operator~(void)
    {
        Complex result(this->realPart, -this->complexPart);
        return result;
    }
    Complex operator+(const Complex &object)
    {
        Complex result(this->realPart + object.realPart, this->complexPart + object.complexPart);
        return result;
    }
    Complex operator-(const Complex &object)
    {
        Complex result(this->realPart - object.realPart, this->complexPart - object.complexPart);
        return result;
    }
    Complex operator*(const Complex &object)
    {
        double a = this->realPart, b = this->complexPart, c = object.realPart, d = object.complexPart;
        Complex result(a * c - b * d, a * d + b * c);
        return result;
    }
    Complex operator/(Complex &object)
    {
        Complex result = *this * ~object;
        double denominator = (object * ~object).realPart;
        result.realPart /= denominator;
        result.complexPart /= denominator;
        return result;
    }
    Complex operator=(const Complex &object)
    {
        this->realPart = object.realPart;
        this->complexPart = object.complexPart;
        return *this;
    }
};

ostream &operator<<(ostream &out, const Complex &object)
{
    out << object.realPart << " + " << object.complexPart << "i";
    return out;
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