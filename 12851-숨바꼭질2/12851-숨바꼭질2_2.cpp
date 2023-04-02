#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;

int cnt;
int minSec;
bool visited[MAX];

int minSecond(int N, int K)
{
    queue<pair<int, int>> q;

    q.push(make_pair(N, 0));
    visited[N] = true;

    while (!q.empty())
    {
        int curLoc = q.front().first;
        int curSec = q.front().second;
        q.pop();

        visited[curLoc] = true;

        if (minSec && minSec == curSec && curLoc == K)
            cnt++;

        if (!minSec && curLoc == K)
        {
            minSec = curSec;
            cnt++;
        }

        if (curLoc + 1 < MAX && !visited[curLoc + 1])
            q.push(make_pair(curLoc + 1, curSec + 1));
        if (curLoc - 1 >= 0 && !visited[curLoc - 1])
            q.push(make_pair(curLoc - 1, curSec + 1));
        if (curLoc * 2 < MAX && !visited[curLoc * 2])
            q.push(make_pair(curLoc * 2, curSec + 1));
    }
    return minSec;
}

int main(void)
{
    int N, K;
    cin >> N >> K;

    cout << minSecond(N, K) << "\n";
    cout << cnt << endl;

    return 0;
}