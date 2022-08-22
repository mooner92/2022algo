#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0, c;
    double p = 0;
    while (true)
    {
        c = n;
        while (true)
        {
            if (c % 5 == 0)
            {
                c /= 5;
                ans++;
            }
            else
                break;
        }
        n--;
        if (!n)
            break;
    }
    cout << ans;
}