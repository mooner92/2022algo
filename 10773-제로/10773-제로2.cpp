#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    stack<int> s;
    int sum = 0;
    for (int i = 0; i < tc; i++)
    {
        int q;
        cin >> q;
        if (q != 0)
            s.push(q);
        else
        {
            s.pop();
        }
    }
    int k = s.size();
    for (int i = 0; i < k; i++)
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}

// s.size()랑
// k = s.size() 랑은 값차이가 남