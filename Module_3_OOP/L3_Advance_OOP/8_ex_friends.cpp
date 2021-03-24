// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square
{
    // Add public constructor to Square, initialize side
public:
    Square(int s) : side_(s) {}

private:
    // Add friend class Rectangle
    friend class Rectangle;
    // Add private attribute side
    int side_;
};

// Define class Rectangle
class Rectangle
{
    // Add public function to Rectangle: Area()
public:
    int Area();
    // Define a Rectangle constructor that takes a Square
    Rectangle(Square a) : width_(a.side_), height_(a.side_) {}

    // Add private attributes width, height;
private:
    int width_;
    int height_;
};

// Define Area() to compute area of Rectangle
int Rectangle::Area()
{
    return width_ * height_;
}

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}