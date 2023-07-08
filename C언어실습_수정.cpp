#include <stdio.h>

int main()
{
    int x = 5;
    printf("%d", x++); // 5출력
    printf("%d", x);   // 6출력

    int x = 5;
    printf("%d", ++x); // 6출력
    printf("%d", x);   // 6출력
    int y = 4;

    if (x > 10)
    {
        if (y > 10)
        {
            x++;
        }
    }
    // 위 중첩 조건문을 아래와 같이 다중조건을 사용하여 작성할 수도 있음
    if (x > 10 && y > 10)
        x++;
}
