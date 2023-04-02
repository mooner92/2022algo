#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, k, p;
    priority_queue<int, vector<int>, greater<>> q;
    cin >> tc;
    char c;
    for (int i = 0; i < tc; i++)
    {
        int cnt = 0;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c >> p;
            if (c == 'I')
            {
                q.push(p);
                cnt++;
            }
            else if (c == 'D')
            {
                if (!q.empty())
                {
                    if (p == 1)
                        q.pop();
                    else if (p == -1)
                        cnt--;
                }
            }
        }
        if (q.empty())
            cout << "EMPTY\n";
        else
        {
            cout << q.top() << " ";
            for (int l = 0; l < cnt; l++)
            {
                q.pop();
            }
            cout << q.top();
        }
    }
}