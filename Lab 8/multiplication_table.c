#include <stdio.h>

int multiplication(int m, int i)
{
    printf("\n");
    printf("%d x %d: %d", m, i, m * i);
    if (i < 10)
    {
        multiplication(m, i + 1);
    }
}

int main()
{
    multiplication(10, 1);
    return 0;
}