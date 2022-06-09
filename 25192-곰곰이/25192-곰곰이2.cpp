#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<string> s;
    vector<bool> snap(n, false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        s.push_back(a);
    }
}