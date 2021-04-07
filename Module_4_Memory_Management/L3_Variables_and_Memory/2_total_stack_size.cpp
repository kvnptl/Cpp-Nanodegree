#include <stdio.h>

void MyFunc(int a)
{
    int k = 5;
    a++;
    printf("Base addr: %p", &k);
    printf("  Current addr: %p \n", &a);
    MyFunc(a);
}

int main()
{
    int b = 1;
    MyFunc(b);
    return 0;
}