#include <iostream>
#include <vector>
#include <algorithm>
// pair 사용하여 풀이하거나 map사용
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<vector<string>> v1(26);
    vector<string> s1;
    string s, p;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        v1[s[0] - 97].push_back(p);
    }
    int t;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        t = s[0] - 97;
        if (binary_search(v1[t].begin(), v1[t].end(), s))
        {
            s1.push_back(s);
        }
    }
}