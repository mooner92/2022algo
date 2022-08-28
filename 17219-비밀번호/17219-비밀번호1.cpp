#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<map<string, string>> v1(26);
    int n, m;
    cin >> m >> n;
    string s1, s2;
    for (int i; i < n; i++)
    {
        cin >> s1 >> s2;
        v1[s1[0] - 97].insert({s1, s2});
    }
    for (int i; i < m; i++)
    {
        cin >> s1;
    }
}