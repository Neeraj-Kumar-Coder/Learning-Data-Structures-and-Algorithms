#include <bits/stdc++.h>

using namespace std;

class Test
{
private:
    int value;

public:
    Test(void) {}
    Test(const Test &obj)
    {
        cout << "Copy Constructor Called!" << '\n';
        value = obj.value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    void show(void)
    {
        cout << this->value << '\n';
    }
};

int main(void)
{
    Test obj;
    obj.setValue(12);
    Test obj1 = obj;
    obj.show();
    obj1.show();
    return 0;
}