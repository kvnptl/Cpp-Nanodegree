#include <iostream>

int main()
{
    int i = 1;
    int &j = i;
    ++i;
    ++j;
    delete &j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    return 0;
}