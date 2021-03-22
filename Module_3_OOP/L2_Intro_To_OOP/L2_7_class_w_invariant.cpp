#include <iostream>
#include <cassert>

class Date
{
public:
    int Day() { return this->day; }
    void Day(int d)
    {
        if (d > 0 && d < 32)
            this->day = d;
    }

    void Month(int m)
    {
        if (m > 0 && m < 13)
            this->month = m;
    }
    int Month() { return this->month; }

    void Year(int y)
    {
        if (y > 0)
            this->year = y;
    }
    int Year() { return this->year; }

private:
    int day{1};
    int month{1};
    int year{0};
};

// Test in main
int main()
{
    Date date;
    date.Day(-1);
    date.Month(14);
    date.Year(2000);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);
}
