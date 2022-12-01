#include <bits/stdc++.h>

using namespace std;

class Base
{
private:
    int value;

public:
    Base(void) {}
    explicit Base(const int value) { this->value = value; }
    void show(void) { cout << this->value << '\n'; }
};

int main(void)
{
    cout << "Learning about the explicit constructor in c++ classes\n";
    Base a(10);
    // Base b = 10; // Implicitily calls the constructor when explicit keyword is NOT used
    a.show();
    // b.show();
    return 0;
}