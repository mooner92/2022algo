#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
bool visited[400004];
int ds[400004];
void cal(int n, int level) // n*level번 만에 이동함을 나타냄
{
    if (!visited[n - 1] && ds[n - 1] > level)
    {
        visited[n - 1] = true;
        ds[n - 1] = level;
    }
    if (!visited[n + 1] && ds[n + 1] > level)
    {
        visited[n + 1] = true;
        ds[n + 1] = level;
    }
    if (!visited[n * 2] && ds[n * 2] > level)
    {
        visited[n * 2] = true;
        ds[n * 2] = level;
    }
    if (1 < n && n < 100001)
    {
        cal(n - 1, level + 1);
        cal(n + 1, level + 1);
        cal(n * 2, level + 1);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    fill(ds, ds + 400003, INF);
    if (n > k)
    {
        cout << n - k;
        return 0;
    }
    else if (n == k)
    {
        cout << 0;
        return 0;
    }
    else
    {
        ds[n] = 0;
        cal(n, 0);
    }
    cout << ds[n];
}