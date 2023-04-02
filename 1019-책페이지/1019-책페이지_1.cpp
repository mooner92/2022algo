#include <iostream>
#include <cmath>
using namespace std;
int ds[11]; // 1~10로 계산
int main()
{
    int n;
    int p = 0;
    cin >> n;
    while (n != 0)
    {
        int h = n % 10;
        if (h == 0)
        {
            h = 10;
        }
        if (n / 10 != 0)
        {
            for (int i = 0; i < 10; i++)
            {
                ds[i] += pow(10, p);
            }
        }

        for (int i = 0; i < h; i++)
        {
            ds[i] += pow(10, p);
        }

        n /= 10;
        p++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ds[i] << " ";
    }
}