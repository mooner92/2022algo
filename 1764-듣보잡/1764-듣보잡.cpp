#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <algorithm>
// hash를 0,1번째 수의 합으로 설정해보기 -> 반례 :: 사람이름이 한글자로 주어질 경우

using namespace std;
int main()
{
    vector<vector<string>> hash(26);
    // priority_queue<string, vector<string>, greater<string>> ans;
    vector<string> v1;
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
    for (int i = 0; i < m; i++) //여기서 O(500,000 * 500,000으로 시간초과)  ->  한 이름이 500,000개 나오는 경우
    {                           // bin_search로 시간초과는 해결
        cin >> s;
        k = s[0] - 97;

        if (binary_search(hash[k].begin(), hash[k].end(), s))
        {
            // ans.push(s);
            v1.push_back(s);
        }
    }
    // cout << ans.size() << "\n";
    cout << v1.size() << "\n";
    sort(v1.begin(), v1.end());
    for (auto o : v1)
    {
        cout << o << "\n";
    }
    /*
    while (!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
    */
}