#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001];
int N, K, result = 987654321;
int cnt_p = 0;
int cnt = 0;

bool valid(int n)
{
    if (n < 0 || n > 100000 || visited[n])
        return false;
    else
        return true;
}

void bfs(int n)
{
    while (!q.empty())
    {
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (data == K && depth <= result)
        {

            result = depth;
            // break;
            cnt++;
            visited[data] = 0;
        }
        if (valid(data - 1))
        {
            visited[data - 1] = true;
            q.push({data - 1, depth + 1});
        }
        if (valid(data + 1))
        {
            visited[data + 1] = true;
            q.push({data + 1, depth + 1});
        }
        if (valid(data * 2))
        {
            visited[data * 2] = true;
            q.push({data * 2, depth + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    q.push({N, 0});
    visited[N] = true;
    bfs(N);

    cout << result << "\n"
         << cnt;
    return 0;
}