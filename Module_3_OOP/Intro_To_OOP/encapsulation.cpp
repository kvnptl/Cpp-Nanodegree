#include <cassert>

class Date
{
public:
    Date(int day, int month, int year);
    int Day() const { return day_; }
    void Day(int day);
    int Month() const { return month_; }
    void Month(int month);
    int Year() const { return year_; }
    void Year(int year);

private:
    int DayInMonth();
    bool LeapYear();
    int day_{1};
    int month_{1};
    int year_{0};
};

Date::Date(int day, int month, int year)
{
    Year(year);
    Month(month);
    Day(day);
}

bool Date::LeapYear()
{
    if (this->year_ % 4 != 0)
    {
        return false;
    }
    else if (this->year_ % 100 != 0)
    {
        return true;
    }
    else if (this->year_ % 400 != 0)
    {
        return true;
    }
    else
    {
        return true;
    }
}

int Date::DayInMonth()
{
    if (this->month_ == 2)
    {
        return LeapYear() ? 29 : 28;
    }
    else if (this->month_ == 4 || this->month_ == 6 || this->month_ == 9 || this->month_ == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

void Date::Day(int day)
{
    if (day >= 1 && day <= DayInMonth())
        day_ = day;
}

void Date::Month(int month)
{
    if (month >= 1 && month <= 12)
        month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main()
{
    Date date(29, 2, 2016);
    assert(date.Day() == 29);
    assert(date.Month() == 2);
    assert(date.Year() == 2016);

    Date date2(29, 2, 2019);
    assert(date2.Day() != 29);
    assert(date2.Month() == 2);
    assert(date2.Year() == 2019);
}