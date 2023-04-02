#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

queue<pair<int, int>> q;
bool visited[100001];
int spot[100001];
int N, K, result;

bool valid(int n)
{
    if (n < 0 || n > 100000 || visited[n])
        return false;
    return true;
}

void bfs(int n)
{
    while (!q.empty())
    {
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (data == K)
        {
            result = depth;
            break;
        }
        if (valid(data - 1))
        {
            visited[data - 1] = true;
            q.push({data - 1, depth + 1});
            spot[data - 1] = data;
        }
        if (valid(data + 1))
        {
            visited[data + 1] = true;
            q.push({data + 1, depth + 1});
            spot[data + 1] = data;
        }
        if (valid(data * 2))
        {
            visited[data * 2] = true;
            q.push({data * 2, depth + 1});
            spot[data * 2] = data;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> qp;
    cin >> N >> K;
    q.push({N, 0});
    visited[N] = true;
    bfs(N);

    cout << result << "\n";
    while (K != N)
    {
        qp.push_front(K);
        K = spot[K];
    }
    qp.push_front(N);
    while (!qp.empty())
    {
        cout << qp.front();
        cout << " ";
        qp.pop_front();
    }
    return 0;
}