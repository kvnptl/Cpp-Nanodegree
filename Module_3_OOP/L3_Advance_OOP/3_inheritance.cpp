#include <iostream>
#include <string>
using std::string;

class Vehicle
{
public:
    int wheels = 0;
    string color = "blue";
    bool airbag = false;

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

class Bicycle : public Vehicle
{
public:
    bool kickstand = true;
};

class Truck : public Vehicle
{
public:
    int seat = 3;
};

int main()
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if (car.sunroof)
        std::cout << "And a sunroof!\n";
    Vehicle vehicle;
    vehicle.airbag = true;

    Truck truck;
    truck.seat = 30;
    std::cout << "My truck has " << truck.seat << " seats"
              << "\n";
};