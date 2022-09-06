#include <iostream>
#include <vector>
using namespace std;

bool visited[1001] = {};

void dfs_recursion(const vector<vector<int>> &adj_list, int s)
{
    if (visited[s])
        return;

    visited[s] = true;
    cout << s << ", ";

    for (int v : adj_list[s])
        dfs_recursion(adj_list, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> v1(1001, vector<int>(1001, 0));
    int n, m, l1, l2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l1 >> l2;
        v1[l1].push_back(l2);
    }
}