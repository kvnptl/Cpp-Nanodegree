#include <stdio.h>
#include <stdlib.h>

//Malloc - Memory allocation

int main()
{
    int *p = (int *)malloc(sizeof(int));
    printf("address=%p, value=%d\n", p, *p);
    // reserve memory for several integers
    int *p2 = (int *)malloc(3 * sizeof(int));
    printf("address=%p, value=%d\n", p2, *p2);

    return 0;
}