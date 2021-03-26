#include <assert.h>
#include <vector>

// TODO: Declare a generic, templatized average function
template <typename T>
T average(T a, T b)
{
    return (a + b) / 2;
}

int main()
{
    assert(average(2.0, 5.0) == 3.5);

    //-std=c++17 argument can compile below line (compiler automatically detects datatype)
    // std::vector v{1, 2, 3};
}