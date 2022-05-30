#include <iostream>
#include <vector>
using namespace std;

string phone1, phone2;
vector<int> v;
void init()
{
    cin >> phone1 >> phone2;
    for (int i = 0; i < 8; i++)
    {
        // ASCII CODE '0' is 48
        v.push_back(int(phone1[i]) - 48);
        v.push_back(int(phone2[i]) - 48);
    }
}

void solve(vector<int> v)
{
    if (v.size() == 2)
    {
        cout << v[0] << v[1];
        return;
    }
    vector<int> v2;
    for (int i = 1; i < v.size(); i++)
    {
        v2.push_back((v[i - 1] + v[i]) % 10);
    }
    solve(v2);
}

int main()
{
    init();
    solve(v);
}