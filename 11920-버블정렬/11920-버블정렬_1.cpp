#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[100001];

int main()
{
    int n, k;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
        q.push(arr[i]);

    for (int i = 0; i <= n - k; i++)
    {
        q.push(arr[i + k]);
        arr[i] = q.top();
        q.pop();
    }

    for (int i = 0; i < n - k; i++)
        cout << arr[i] << " ";

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}