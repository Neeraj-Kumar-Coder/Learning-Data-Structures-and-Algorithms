#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp = {
    {"Jan", 1},
    {"Feb", 2},
    {"Mar", 3},
    {"Apr", 4},
    {"May", 5},
    {"Jun", 6},
    {"Jul", 7},
    {"Aug", 8},
    {"Sep", 9},
    {"Oct", 10},
    {"Nov", 11},
    {"Dec", 12}};

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Person
{
public:
    int startDate;
    int startMonth;
    int startYear;
    int endDate;
    int endMonth;
    int endYear;

    Person(string startStr, string endStr)
    {
        int n1 = startStr.length(), n2 = endStr.length();
        stringstream converter(startStr.substr(n1 - 4, 4));
        converter >> (this->startYear);
        converter = stringstream(endStr.substr(n2 - 4, 4));
        converter >> (this->endYear);
        this->startMonth = mp[startStr.substr(n1 - 7, 3)];
        this->endMonth = mp[endStr.substr(n2 - 7, 3)];
        int offset = 0;
        if (isdigit(startStr[1]))
            offset++;
        converter = stringstream(startStr.substr(0, 1 + offset));
        converter >> (this->startDate);

        offset = 0;
        if (isdigit(endStr[1]))
            offset++;
        converter = stringstream(endStr.substr(0, 1 + offset));
        converter >> (this->endDate);
    }
};

bool isLeap(int year)
{
    return year % 400 == 0 || year % 100 == 0 || year % 4 == 0;
}

void limitFill1(Person person, int &limit)
{
    for (int i = 1000; i < person.startYear; i++)
    {
        limit += 365;
        if (isLeap(i))
            limit++;
    }

    for (int i = 1; i < person.startMonth; i++)
    {
        limit += day[i];
    }

    if (isLeap(person.startYear))
        limit++;

    for (int i = 1; i <= person.startDate; i++)
    {
        limit++;
    }
}

void limitFill2(Person person, int &limit)
{
    for (int i = 1000; i < person.endYear; i++)
    {
        limit += 365;
        if (isLeap(i))
            limit++;
    }

    for (int i = 1; i < person.endMonth; i++)
    {
        limit += day[i];
    }

    if (isLeap(person.endYear))
        limit++;

    for (int i = 1; i <= person.endDate; i++)
    {
        limit++;
    }
}

int main(void)
{
    string montiStart, montiEnd, rihaStart, rihaEnd;
    cin >> montiStart >> montiEnd >> rihaStart >> rihaEnd;

    Person monti(montiStart, montiEnd), riha(rihaStart, rihaEnd);

    int limit1 = 0, limit2 = 0, limit3 = 0, limit4 = 0;

    limitFill1(monti, limit1);
    limitFill2(monti, limit2);
    limitFill1(riha, limit3);
    limitFill2(riha, limit4);

    int start = max(limit1, limit3);
    int end = min(limit2, limit4);

    int days = 0;
    for (int i = start; i <= end; i++)
    {
        days++;
    }

    cout << days << '\n';
    return 0;
}