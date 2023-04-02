#include <stdio.h>
#include <string.h>
int main()
{
    char a[101];
    char b[100][100];
    int max = -99;
    int cnt = 0;
    int i;
    int k;
    fgets(a, 101, stdin);
    printf("%ld\n", strlen(a));
    for (i = 0; i < strlen(a) - 2; i++)
    {
        if (a[i] != ' ')
        {
            cnt++;
        }
        else if (a[i] == ' ')
        {
            if (max < cnt)
            {
                max = cnt;
                k = i;
            }
            cnt = 0;
        }
    }
    int l = 0;
    char *ptr = strtok(a, " "); // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

    while (ptr != NULL) // 자른 문자열이 나오지 않을 때까지 반복
    {
        b[l] = *ptr;
        l++;

        ptr = strtok(NULL, " "); // 다음 문자열을 잘라서 포인터를 반환
    }
    for (i = 0; i < l; i++)
    {
        if (max == strlen(b[i]))
        {
            printf("%s\n", b[i]);
        }
    }
}
