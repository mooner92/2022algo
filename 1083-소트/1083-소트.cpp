#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, s;
    vector<int> v1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int maxIdx = max_element(v1.begin(), v1.end()) - v1.begin(); // max값의 인덱스
        if (maxIdx > s)
        {
        }
    }
}