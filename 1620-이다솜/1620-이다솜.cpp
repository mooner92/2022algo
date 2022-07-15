#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); //없으면 시간 초과
    int n = 0, m = 0;
    cin >> n >> m;
    string strarr[100001];
    unordered_map<string, int> p;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        p.insert(make_pair(s, i));
        strarr[i] = s;
    }
    for (int i = 0; i < m; i++)
    {
        string s1;
        cin >> s1;
        if (p.find(s1) != p.end())
        {
            cout << p.find(s1)->second << "\n";
        }
        else
        {
            int j = stoi(s1);
            cout << strarr[j] << "\n";
        }
    }
}
