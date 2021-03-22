#include <cassert>
#include <stdexcept>
#include <iostream>

// TODO: Define class Pyramid
class Pyramid
{

    // public class members
public:
    // constructor
    Pyramid(int l, int w, int h) : length_(l), width_(w), height_(h)
    {
        Validate();
    }

    // accessors
    int Length() const { return length_; }
    int Width() const { return width_; }
    int Height() const { return height_; }
    int Volume() const { return (length_ * width_ * height_) / 3; }

    // mutators
    void Length(int l);
    void Width(int w);
    void Height(int h);

    // public Volume() function

    // private class members
private:
    int length_;
    int width_;
    int height_;
    void Validate()
    {
        if (length_ < 0 || width_ < 0 || height_ < 0)
        {
            throw std::invalid_argument("negative values");
        }
    }
};

void Pyramid::Length(int l)
{
    if (l > 0)
    {
        length_ = l;
    }
}

void Pyramid::Width(int w)
{
    if (w > 0)
    {
        width_ = w;
    }
}

void Pyramid::Height(int h)
{
    if (h > 0)
    {
        height_ = h;
    }
}

// Test
int main()
{
    Pyramid pyramid(4, 5, 6);
    assert(pyramid.Length() == 4);
    assert(pyramid.Width() == 5);
    assert(pyramid.Height() == 6);
    assert(pyramid.Volume() == 40);

    bool caught{false};
    try
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch (...)
    {
        std::cout << "Entered negative values"
                  << "\n";
        caught = true;
    }
    assert(caught);
}