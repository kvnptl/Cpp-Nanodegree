#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere
{
public:
    // Constructor
    Sphere(int r) : radius_(r), volume_(pi_ * 4 / 3 * pow(radius_, 3))
    {
        if (r < 0)
            throw std::invalid_argument("radius must be positive");
    }

    // Accessors
    int Radius() const { return radius_; }
    float Volume() const { return volume_; };

private:
    // Private members
    int radius_;
    float volume_;
    const float pi_ = 3.14159;
};

// Test
int main(void)
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}