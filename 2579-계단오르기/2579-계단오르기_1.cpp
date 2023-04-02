#include <iostream>
#include <algorithm>
using namespace std;
int DP[301];
int stairs[301];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stairs[i];
    }
    DP[0] = stairs[0];
    DP[1] = max(stairs[1] + stairs[0], stairs[1]);
    DP[2] = max(stairs[1] + stairs[2], stairs[2] + stairs[0]);
    for (int i = 3; i < n; i++)
    {
        DP[i] = max(DP[i - 2] + stairs[i], stairs[i - 1] + stairs[i] + DP[i - 3]);
    }
    cout << DP[n - 1];
}