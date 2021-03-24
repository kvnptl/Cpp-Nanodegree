// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Vehicle
{
public:
    int wheels = 0;
    string color = "blue";

    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle
{
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle
{
public:
    bool kickstand = true;
    void Pri()
    {
        Print();
    }
};

class Scooter : private Vehicle
{
public:
    bool electric = false;
    void Prin()
    {
        Print();
    }
};

int main()
{
    Car car;
    car.wheels = 4;
    // car.Print();

    Bicycle bicycle;
    // bicycle.wheels = 2;
    // cout << "Value : " << bicycle.kickstand << "\n";
    bicycle.Pri();

    Scooter scooter;
    scooter.electric = true;
    // scooter.wheels = 3;
    scooter.Prin();
};