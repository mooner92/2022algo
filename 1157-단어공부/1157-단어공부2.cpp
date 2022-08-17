#include <stdio.h>
#include <string.h>
int main()
{
    char c[1000001] = "";
    int f[26] = {
        0,
    };
    scanf("%s", c);
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 97 && c[i] < 123)
        {
            // c[i]-=32;
            f[c[i] - 97]++;
        }
        else
        {
            f[c[i] - 65]++;
        }
    }
    int max = -1;

    for (int i = 0; i < 26; i++)
    {
        if (f[i] > max)
            max = f[i];
    }
}