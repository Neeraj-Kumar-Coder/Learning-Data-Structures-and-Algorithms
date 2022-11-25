#include <bits/stdc++.h>

using namespace std;

class DataType
{
private:
    int value;
    char character;
    double points;

public:
    static int counter;

    DataType(void)
    {
        value = ++counter;
        cout << "Constructor\n";
    }

    int getValue(void)
    {
        return value;
    }

    ~DataType(void)
    {
        cout << "Destructor\n";
    }
};

int DataType::counter = 0;

int main(void)
{
    // Placement new is another version of the new operator

    // Normal new operator does two things:
    // 1. Allocate memory by calling the kernal
    // 2. Build the object by calling the constructor

    // In case of placement new we bulid the object by calling the constructor explicitily on the pre booked memory

    char *memory = new char[5 * sizeof(DataType)];

    int offset = 0;

    DataType *d1 = new (&memory[offset]) DataType();
    offset += sizeof(DataType);

    DataType *d2 = new (&memory[offset]) DataType();
    offset += sizeof(DataType);

    DataType *d3 = new (&memory[offset]) DataType();
    offset += sizeof(DataType);

    DataType *d4 = new (&memory[offset]) DataType();
    offset += sizeof(DataType);

    DataType *d5 = new (&memory[offset]) DataType();

    cout << (d1->getValue()) << '\n';
    cout << (d2->getValue()) << '\n';
    cout << (d3->getValue()) << '\n';
    cout << (d4->getValue()) << '\n';
    cout << (d5->getValue()) << '\n';

    d1->~DataType();
    d2->~DataType();
    d3->~DataType();
    d4->~DataType();
    d5->~DataType();

    // Equivalent to:
    // if (val < 4)
    //     return 4;
    // else if (val > 7)
    //     return 7;
    // else
    //     return val;

    int val = 4;
    cout << clamp(val, 4, 7) << '\n';
    return 0;
}