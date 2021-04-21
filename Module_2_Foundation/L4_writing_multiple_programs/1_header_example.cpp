
#include "1_header_example.h"
#include <iostream>
using std::cout;

void AddOneToEach(std::vector<int> v)
{

    for (int a : v)
    {
        // cout << "Original: " << a << "\n";
        a++;
        cout << "Increament: " << a << "\n";
    }
}
int IncrementAndComputeVectorSum(std::vector<int> v)
{
    int sum{0};

    AddOneToEach(v);

    for (int a : v)
    {
        sum = a + sum;
    }

    return sum;
}

int main()
{
    std::vector<int> a{1, 2, 3, 4, 5};
    int n = IncrementAndComputeVectorSum(a);
    cout << "Sum of a vector: " << n << "\n";
}
