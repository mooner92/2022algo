#include <stdio.h>

int main()
{
    int k;
    int *p = &k;
    scanf("%d", p);
    while ((*p)--)
    {
        // printf("%d",(*p)--);
        printf("*");
    }
}
//////