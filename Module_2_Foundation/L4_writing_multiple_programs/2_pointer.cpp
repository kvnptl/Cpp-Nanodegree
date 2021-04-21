#include <iostream>

using std::cout;

void AddOne(int *j)
{
    (*j)++;
}

int *AddOne(int &j)
{
    j++;
    return &j;
}

int *AddOne1(int *j)
{
    (*j)++;
    return j;
}

int main()
{
    int i = 5;

    int *pi = &i;
    AddOne(pi); // or AddOne(&i)
    cout << i << "\n";

    int *my_pointer = AddOne(i);
    cout << "The value of i: " << i << "\n";
    cout << "my_pointer value: " << *my_pointer << "\n";

    int *my_pointer_2 = AddOne1(pi);
    cout << "The value of i: " << i << "\n";
    cout << "my_pointer_2 value: " << *my_pointer_2 << "\n";
}