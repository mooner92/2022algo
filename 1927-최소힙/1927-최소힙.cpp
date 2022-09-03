#include <iostream>
#include <queue>
//#include <functional>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    priority_queue<long long, vector<long long>, greater<long long>> pql;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        pql.push(k);
        if (k == 0)
        {
            if (pql.empty())
                cout << "0\n";
            else
            {
                cout << pql.top() << "\n";
                pql.pop();
            }
        }
    }
} //