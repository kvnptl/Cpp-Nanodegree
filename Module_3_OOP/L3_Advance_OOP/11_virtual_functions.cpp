// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>
#include <iostream>

// TODO: Define pi
#define PI 3.14

// TODO: Define the abstract class Shape
class Shape
{

public:
    // TODO: Define public virtual functions Area() and Perimeter()
    // TODO: Append the declarations with = 0 to specify pure virtual functions
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : public Shape
{
public:
    // TODO: Declare public constructor
    Rectangle(double w, double h) : width_(w), height_(h) {}
    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const
    {
        return width_ * height_;
    }
    double Perimeter() const
    {
        return width_ * 2 + height_ * 2;
    }

private:
    // TODO: Declare private attributes width and height
    int width_;
    int height_;
};

// TODO: Define Circle to inherit from Shape
class Circle : public Shape
{
public:
    // TODO: Declare public constructor
    Circle(double r) : radius_(r) {}

    // TODO: Override virtual base class functions Area() and Perimeter()
    double Area() const
    {
        return PI * radius_ * radius_;
    }
    double Perimeter() const
    {
        return 2 * PI * radius_;
    }

private:
    // TODO: Declare private member variable radius
    double radius_;
};

// Test in main()
int main()
{
    double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
}