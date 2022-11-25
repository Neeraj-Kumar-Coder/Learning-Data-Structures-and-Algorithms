#include <bits/stdc++.h>

using namespace std;

class Base
{
public:
    virtual void greet(void) final
    {
        cout << "Hello\n";
    }
};

class Derived : public Base
{
public:
    void greet(int x)
    {
        cout << "Myself\n";
    }
};

class Test
{
private:
    const int gravity;
    static int friction;

public:
    Test(void) : gravity(9) {}

    Test(int gravityValue) : gravity(gravityValue) {}

    int getGravity(void)
    {
        return gravity;
    }

    int getFriction(void)
    {
        return friction;
    }

    void greet(int x)
    {
        cout << "Hello" << x << '\n';
    }

    void greet(char ch)
    {
        cout << "Hello" << ch << '\n';
    }
};

int Test::friction;

int main(void)
{
    // Test obj(199);
    // cout << obj.getGravity() << '\n';
    // cout << obj.getFriction() << '\n';

    // obj.greet();

    // Derived ob;
    // ob.greet();

    Derived dobj;
    Base *ptr = &dobj;
    dobj.greet(2);
    ptr->greet();
    return 0;
}