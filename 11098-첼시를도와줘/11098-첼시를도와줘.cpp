#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n, p;
    cin >> n;
    while (n--)
    {
        cin >> p;
        vector<pair<int, string>> s(p);
        int ans = 0, i = 0, ex = 0;
        while (p--)
        {
            cin >> s[i].first >> s[i].second;
            if (s[i].first > ex)
            {
                ex = s[i].first;
                ans = i;
            }
            i++;
        }
        cout << s[ans].second << '\n';
    }
}