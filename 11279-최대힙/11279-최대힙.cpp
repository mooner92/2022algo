#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long k;
    priority_queue<long long> pq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(k);
        }
    }
}