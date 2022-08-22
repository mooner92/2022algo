#include <iostream>
#include <string>
//도수분포표를 사용한 풀이
using namespace std;

string s1[7] = {"add", "remove", "check", "toggle", "empty", "all"};

void process(string s, int k)
{
}

int main()
{
    int f[22] = {
        0,
    };
    string s;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        if (s == s1[5]) // all이 아닌 경우
        {
            for (int j = 1; j < 21; j++)
            {
                f[j] = 1;
            }
            continue;
        }
        process(s, k);
    }
}