#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int bank[10001] = {
        0,
    };
    int zc = 0, n;
    long long fairy = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bank[i]);
    }
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (bank[i] < 0)
            {
                zc = 0;
                fairy++;
                if (i == n - 1)
                {
                    bank[0] += bank[i];     //다음수 빼줌
                    bank[i - 1] += bank[i]; //전 수 빼줌
                    bank[i] = abs(bank[i]); //현 수 abs
                }
                else if (i == 0)
                {
                    bank[n - 1] += bank[i]; //다음수 빼줌
                    bank[i + 1] += bank[i]; //전 수 빼줌
                    bank[i] = abs(bank[i]); //현 수 abs
                }
                else
                {
                    bank[i + 1] += bank[i]; //다음수 빼줌
                    bank[i - 1] += bank[i]; //전 수 빼줌
                    bank[i] = abs(bank[i]); //현 수 abs
                }
            }
            else
                zc++;
            if (zc == n)
                break; //기저조건
        }
        if (zc == n)
            break;
    }
    printf("%lld", fairy);
}