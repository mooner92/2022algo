#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s[16] = {
    "ENFP", "ENFJ", "ENTP", "ENTJ",
    "ESFP", "ESFJ", "ESTP", "ESTJ",
    "INFP", "INFJ", "INTP", "INTJ",
    "ISFP", "ISFJ", "ISTP", "ISTJ"};

int main()
{
    int n, m;
    cin >> n >> m;
    string k = "qwer";
    reverse(k.begin(), k.end());
    cout << k;

    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        v.push_back(a);
    }
    if (n >= 4 && m >= 4)
    {
    }
    else
    {
        cout << "0";
        return 0;
    }
}

int searchStar(vector<string> v1, int n1, int m1)
{

    return 0;
}

string reverseStr(string x)
{
    reverse(x.begin(), x.end());
    return x;
}