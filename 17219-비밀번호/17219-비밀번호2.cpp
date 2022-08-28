#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s1, s2;
    map<string, string> acc;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        acc[s1] = s2;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s1;
        cout << acc[s1] << "\n";
    }
}