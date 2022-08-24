#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;
int main()
{
    vector<vector<string>> hash(26);
    priority_queue<string, vector<string>, greater<string>> ans;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        hash[s[0] - 97].push_back(s);
    }
    int k;
    for (int i = 0; i < 26; i++)
    {
        sort(hash[i].begin(), hash[i].end());
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        k = s[0] - 97;

        if (binary_search(hash[k].begin(), hash[k].end(), s))
        {
            ans.push(s);
        }
    }
    cout << ans.size() << "\n";
    while (!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
}