#include <stdio.h>
int main()
{
    int n;
    char *ptr;
    int sum = 0;
    scanf("%d", &n);
    getchar();
    scanf("%s", ptr);
    for (int i = 0; i < n; i++)
    {
        sum += (*(ptr + i) - '0');
    }
    printf("%d", sum);
    return 0;
}