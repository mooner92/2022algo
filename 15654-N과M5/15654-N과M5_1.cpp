#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX];
int v[MAX];
bool visited[MAX];
void dfs(int k, int l)
{
    if (l == m)
    {
        for (int i = 0; i < l; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            arr[l] = v[i - 1];
            dfs(k, l + 1);
            visited[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v, v + n);
    dfs(1, 0);
}