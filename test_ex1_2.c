#include <stdio.h>
int main()
{
    int arr[10];
    int *p = arr;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &p[i]);
        if (p[i] % 2 == 0)
        {
            p[i] /= 2;
        }
        else
            p[i] *= 2;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d", p[i]);
    }
}
//////