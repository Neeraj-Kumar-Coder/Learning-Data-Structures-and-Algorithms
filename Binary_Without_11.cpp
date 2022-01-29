#include <iostream>

using namespace std;

void generate(string &);
void print(string &);

int main(void)
{
    string bitStr = "000000000000000000000000000000000000000";
    int iteration = 100000000;
    while (iteration--)
    {
        generate(bitStr);
    }
    print(bitStr);
    return 0;
}

void generate(string &num)
{
    int ind = num.length() - 1;
    if (num[ind - 1] == '0')
    {
        if (num[ind] == '0')
        {
            num[ind] = '1';
            return;
        }
        else
        {
            num[ind - 1] = '1';
            num[ind] = '0';
            ind--;
            while (true)
            {
                if (num[ind - 1] == '1')
                {
                    num[ind] = '0';
                    ind--;
                    num[ind] = '0';
                    ind--;
                    num[ind] = '1';
                }
                else
                {
                    return;
                }
            }
        }
    }
    else
    {
        while (true)
        {
            if (num[ind - 1] == '1')
            {
                num[ind] = '0';
                ind--;
                num[ind] = '0';
                ind--;
                num[ind] = '1';
            }
            else
            {
                return;
            }
        }
    }
}

void print(string &num)
{
    bool flag = false;
    for (char ch : num)
    {
        if (ch == '1')
            flag = true;
        if (flag)
            cout << ch;
    }
    cout << '\n';
}