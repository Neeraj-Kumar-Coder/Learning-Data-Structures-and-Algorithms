#include <iostream>
#define DEFAULT_VALUE -1

using namespace std;

// Revision about constructor overloading and initializer list

class BaseClass1
{
public:
    int variable;
    BaseClass1(void) : variable(DEFAULT_VALUE)
    {
        cout << "Base Class 1 constructor called.\n";
    }
    ~BaseClass1(void)
    {
        cout << "Base Class 1 destructor called.\n";
    }
    virtual void say(void)
    {
        cout << "I am Base Class 1.\n";
    }
};

class DerivedClass1 : virtual public BaseClass1
{
public:
    DerivedClass1(void)
    {
        cout << "Derived Class 1 constructor called.\n";
    }
    ~DerivedClass1(void)
    {
        cout << "Derived Class 1 destructor called.\n";
    }
    void say(void)
    {
        cout << "I am Derived Class 1.\n";
    }
};

class DerivedClass2 : virtual public BaseClass1
{
public:
    DerivedClass2(void)
    {
        cout << "Derived Class 2 constructor called.\n";
    }
    ~DerivedClass2(void)
    {
        cout << "Derived Class 2 destructor called.\n";
    }
    void say(void)
    {
        cout << "I am Derived Class 2.\n";
    }
};

class DerivedClass3 : public DerivedClass1, virtual public DerivedClass2
{
public:
    DerivedClass3(void)
    {
        cout << "Derived Class 3 constructor called.\n";
    }
    ~DerivedClass3(void)
    {
        cout << "Derived Class 3 destructor called.\n";
    }
    void say(void)
    {
        cout << "I am Derived Class 3.\n";
    }
};

// Revision about operator overloading

class Number
{
private:
    long long int value;

public:
    Number(void) : value(0) {}
    Number(long long int value) : value(value) {}
    long long int getValue(void) { return value; }
    Number operator=(long long int newValue)
    {
        this->value = newValue;
        return *this;
    }
    Number operator+(Number &object)
    {
        return Number(this->getValue() + object.getValue());
    }
    Number operator-(Number &object)
    {
        return Number(this->getValue() - object.getValue());
    }
    Number operator*(Number &object)
    {
        return Number(this->getValue() * object.getValue());
    }
    Number operator/(Number &object)
    {
        return Number(this->getValue() / object.getValue());
    }
};

ostream &operator<<(ostream &say, Number &object)
{
    say << object.getValue();
    return say;
}

// Size of empty structure and class
struct Empty_Structure
{
    ;
};

class Empty_Class
{
    ;
};

// Final keyword in c++
class Test
{
public:
    virtual void print(void) final
    {
        cout << "Hello\n";
    }
};

class Test_Kid : public Test
{
public:
    // void print(void)
    // {
    //     cout << "Bye\n";
    // }
};

int main(void)
{
    Number a;
    a = 988;
    Number b(12);
    cout << a << '\n'
         << b << '\n';

    Number c = a * b;
    cout << c << '\n';

    cout << "Size of empty structure: " << sizeof(Empty_Structure) << '\n';
    cout << "Size of empty class: " << sizeof(Empty_Class) << '\n';

    Test_Kid tkobj;
    tkobj.print();
    return 0;
}