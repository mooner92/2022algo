#include <iostream>
#include <vector>
#define MAX 1010
using namespace std;
int DP[MAX];
int arr[MAX];
int Max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int maxcnt = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int Answer = 0;
    for (int i = 1; i <= n; i++)
    {
        DP[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (arr[i] > arr[j])
            {
                DP[i] = Max(DP[i], DP[j] + 1);
            }
        }
        Answer = Max(DP[i], Answer);
    }

    cout << Answer << endl;
}