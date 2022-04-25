#include <iostream>
using namespace std;

bool num[10001];

int d(int n)
{
    int temp;
    temp = n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10;
    return temp;
}

void self_number()
{
    int temp;
    num[1] = false;
    for (int i = 0; i < 10000; i++)
    {
        if (i < 10000)
        {
            temp = d(i);
            if (temp < 10000)
                num[temp] = true;
        }
    }
}

int main()
{
    self_number();
    for (int i = 1; i < 10000; i++)
        if (!num[i])
            printf("%d\n", i);
}