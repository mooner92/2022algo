#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0, p = 0, a = 0, b = 0;
    cin >> n;
    while (p != n)
    {
        cnt++;
        for (int i = cnt - 1; i >= 1; i--)
        {
            if (p == n)
                break;
            a = cnt - i;
            b = i;
            p++;
        }
        cnt++;
        for (int i = 1; i < cnt; i++)
        {
            if (p == n)
                break;
            a = cnt - i;
            b = i;
            p++;
        }
    }

    cout << a << "/" << b;
}