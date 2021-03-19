#include <cassert>
#include <iostream>

// TODO: Define public accessors and mutators for the private member variables
struct Date
{
public:
    void Day(int d) { this->day = d; }
    int Day() { return this->day; }
    void Month(int m) { this->month = m; }
    int Month() { return this->month; }
    void Year(int y) { this->year = y; }
    int Year() { return this->year; }

private:
    int day{1};
    int month{1};
    int year{0};
};

int main()
{
    Date date;
    date.Day(29);
    date.Month(8);
    date.Year(1981);
    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);
    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}