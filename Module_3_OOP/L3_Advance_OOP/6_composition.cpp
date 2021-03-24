// Example solution for Circle class
#include <iostream>
#include <cmath>
#include <assert.h>
// Define PI
#define PI 3.14159;

// Define LineSegment struct
struct LineSegment
{
    // Define protected attribute length
public:
    double length;
};

// Define Circle class
class Circle
{
public:
    Circle(LineSegment &radius);
    double Area();

private:
    LineSegment &radius_;
};

// Declare Circle class
Circle::Circle(LineSegment &radius) : radius_(radius) {}

double Circle::Area()
{
    return pow(Circle::radius_.length, 2) * PI;
}

// Test in main()
int main()
{
    LineSegment radius{3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}