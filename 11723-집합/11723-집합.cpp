#include <iostream>
#include <string>
//도수분포표를 사용한 풀이
//캡슐화 최대한으로 이용
using namespace std;

string s1[7] = {"add", "remove", "check", "toggle", "empty", "all"};

int f[22] = {0};

void p_add(int n)
{
    f[n]++;
}
void p_remove(int n)
{
    f[n] = 0;
}
void p_check(int n)
{
    if (f[n])
    {
        printf("1\n");
    }
    else
        printf("0\n");
}
void p_toggle(int n)
{
    if (f[n])
        f[n] = 0;
    else
        f[n]++;
}
void p_empty()
{
    for (int i = 1; i <= 20; i++)
        f[i] = 0;
}
void p_all()
{
    for (int i = 1; i <= 20; i++)
    {
        f[i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == s1[5])
            p_all();
        else if (s == s1[4])
            p_empty();
        else if (s == s1[3])
        {
            cin >> k;
            p_toggle(k);
        }
        else if (s == s1[2])
        {
            cin >> k;
            p_check(k);
        }
        else if (s == s1[1])
        {
            cin >> k;
            p_remove(k);
        }
        else if (s == s1[0])
        {
            cin >> k;
            p_add(k);
        }
    }
}