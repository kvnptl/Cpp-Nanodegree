#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid

// public class members

// constructor

// accessors

// mutators

// public Volume() function

// private class members

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
        caught = true;
    }
    assert(caught);
}