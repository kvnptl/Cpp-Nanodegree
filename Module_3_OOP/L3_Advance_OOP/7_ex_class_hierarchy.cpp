#include <cassert>
#include <iostream>

// TODO: Declare Vehicle as the base class
class Vehicle
{
public:
    int wheels = 0;
};

class Car : public Vehicle
{
public:
    int seats = 4;
};

// TODO: Derive Car from Vehicle

// TODO: Derive Sedan from Car
class Sedan : public Car
{
public:
    bool trunk = false;
};

// TODO: Update main to pass the tests
int main()
{
    Sedan sedan;
    sedan.wheels = 4;
    sedan.trunk = true;
    assert(sedan.trunk == true);
    assert(sedan.seats == 4);
    assert(sedan.wheels == 4);
}