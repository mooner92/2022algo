#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, t;
    cin >> tc;
    while (tc--)
    {
        priority_queue<int, vector<int>, less<int>> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        int cnt1 = 0, cnt2 = 0, psize = 0; //heap을 두개 쓰기 때문에 empty()함수 사용이 힘들어 남아있는 요소의 개수를 세어줄 psize를 만들어주었음
        cin >> t;
        char c;
        int k;
        for (int i = 0; i < t; i++)
        {
            scanf(" %c %d", &c, &k);
            if (c == 'I')
            {
                q1.push(k);
                q2.push(k);
                psize++;
            }
            else if (c == 'D')
            {
                if (k == 1 && psize)
                {
                    q1.pop();
                    psize--;
                }
                else if (k == -1 && psize)
                {
                    q2.pop();
                    psize--;
                }
            }
        }
        if (!psize)
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << q1.top() << " " << q2.top() << "\n";
        }
    }
}