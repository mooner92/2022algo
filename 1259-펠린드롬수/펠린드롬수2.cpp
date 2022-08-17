#include <stdio.h>
#include <string.h>
int main()
{
    for (;;)
    {
        char c[6] = "", c1[6] = "";
        scanf("%s", c);
        if (strcmp(c, "0") == 0)
            break;
        int j = 0;
        for (int i = strlen(c) - 1; i >= 0; i--)
        {
            c1[j] = c[i];
            j++;
        }
        if (strcmp(c, c1) == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
}