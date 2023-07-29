#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_square_sum(int n)
{
    vector<int> dp(n + 1, 2147000000);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (j * j <= i)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
            j++;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << min_square_sum(n) << "\n";

    return 0;
} //