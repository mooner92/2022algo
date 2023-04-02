#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int n, arr[15], ans = 0;

int check(int k)
{
    for (int i = 0; i < k; i++)
    {
        if (arr[k] == arr[i] || k - i == abs(arr[k] - arr[i]))
        {
            return 0;
        }
    }
    return 1;
}

void nq(int q)
{
    if (q == n)
    {
        // cout << ans << "\n";
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        arr[q] = i;
        if (check(q))
        {
            nq(q + 1);
        }
    }
}
int main()
{
    cin >> n;
    nq(0);
    cout << ans;
}