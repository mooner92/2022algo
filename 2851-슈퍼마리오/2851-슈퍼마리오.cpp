#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int s[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cin >> s[i];
    }
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < 10; j++)
    {
        sum2 += s[j];
        if (sum2 >= 100)
        {
            sum1 = sum2 - s[j];
            break;
        }
    }
    int ans = 0;
    if (abs(100 - sum1) >= (sum2 - 100))
    {
        ans = sum2;
    }
    else
    {
        ans = sum1;
    }
    cout << ans;
}