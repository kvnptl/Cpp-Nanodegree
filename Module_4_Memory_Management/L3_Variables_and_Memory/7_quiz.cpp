#include <iostream>

void AddFive(int &v, bool &s)
{
    v += 5;
    s = true;
}

int main()
{
    int val = 0;
    bool success = false;
    AddFive(val, success);
    val += 2;

    std::cout << "val = " << val << ", success = " << success << std::endl;

    return 0;
}