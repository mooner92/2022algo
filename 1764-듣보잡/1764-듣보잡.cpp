#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
// hash를 0,1번째 수의 합으로 설정해보기 -> 반례 :: 사람이름이 한글자로 주어질 경우

using namespace std;
int main()
{
    vector<vector<string>> hash(51);
    priority_queue<string, vector<string>, greater<string>> ans;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        hash[(s[0] - 97) + (s[1] - 97)].push_back(s);
    }
    int k, cnt = 0;
    for (int i = 0; i < m; i++) //여기서 O(500,000 * 500,000으로 시간초과)  ->  한 이름이 500,000개 나오는 경우
    {
        cin >> s;
        k = s[0] - 97 + s[1] - 97;
        for (int j = 0; j < hash[k].size(); j++)
        {
            if (s == hash[k][j])
            {
                ans.push(hash[k][j]);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < ans.size() + 1; i++)
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
}