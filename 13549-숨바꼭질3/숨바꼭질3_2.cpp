#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring> // memset

using namespace std;

#define MAX_SIZE 100001

int N, K;
bool visited[MAX_SIZE];
// 숨바꼭질 1,2 와 다르게 depth를 계산하지 않고 노드 번호와 시간만 계산할 것임
int bfs()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, N});
    visited[N] = true;
    while (!q.empty())
    {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if (x == K)
            return time;

        if (x * 2 < MAX_SIZE && !visited[x * 2])
        {
            q.push({time, x * 2});
            visited[x * 2] = true;
        }

        if (x + 1 < MAX_SIZE && !visited[x + 1])
        {
            q.push({time + 1, x + 1});
            visited[x + 1] = true;
        }

        if (x - 1 >= 0 && !visited[x - 1])
        {
            q.push({time + 1, x - 1});
            visited[x - 1] = true;
        }
    }
}

int main()
{
    cin >> N >> K;
    cout << bfs();
    return 0;
}