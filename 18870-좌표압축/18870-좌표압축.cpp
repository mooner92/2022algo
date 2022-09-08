#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool visited[INT_MAX] = {
        0,
    };
    deque<int> dq;
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 정렬의 우순큐
    vector<int> v1;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (!visited[k])
        {
            pq.push(k); //중복을 피해 인덱스를 작성할 우순큐
            visited[k] = 1;
        }
        v1.push_back(k); //출력에 사용할 벡터
    }
}