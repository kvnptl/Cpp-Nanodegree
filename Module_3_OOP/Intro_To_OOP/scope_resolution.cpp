#include <cassert>

class Date
{
public:
    int Day() const { return day; }
    void Day(int day);
    int Month() const { return month; }
    void Month(int month);
    int Year() const { return year; }
    void Year(int year);

private:
    int day{1};
    int month{1};
    int year{0};
};

// TODO: Define Date::Day(int day)
void Date::Day(int d)
{
    this->day = d;
}

// TODO: Define Date::Month(int month)
void Date::Month(int m)
{
    this->month = m;
}
// TODO: Define Date::Year(int year)
void Date::Year(int y)
{
    this->year = y;
}
// Test in main
int main()
{
    Date date;
    date.Day(29);
    date.Month(8);
    date.Year(1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);
}