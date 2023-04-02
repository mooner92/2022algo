#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int n;
long long cnt[10];

// num보다 작은 수 중 1의 자리 9인 것중 가장 큰 수
int LastIsNine(int num)
{
    while (1)
    {
        if (num % 10 == 9)
            break;
        num--;
    }
    return num;
}

// A < B
// A는 B보다 작은 수 중 10의 거듭제곱 꼴인 가장 큰 수
// ex) B=9876 => A=1000
// digit : 자릿수 (1의 자리, 10의 자리,...)
void AtoB(int A, int B, int digit)
{
    // 한 자리수만 남았을 경우
    if (B < 10)
    {
        for (int i = A; i <= B; i++)
            cnt[i] += (long long)digit;
        return;
    }

    int tmp = LastIsNine(B); // B보다 작은 값중 일의 자리가 9인 가장 큰 수

    // tmp+1부터 B까지 애들 다 구하기
    for (int i = tmp + 1; i <= B; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            int idx = s[j] - '0';
            cnt[idx] += (long long)digit;
        }
    }

    // A부터 tmp까지 구하기
    for (int i = 0; i < 10; i++)
    {
        cnt[i] += (long long)((tmp / 10 - A / 10 + 1) * digit);
    }

    // 나머지 부분 계산
    AtoB(A / 10, tmp / 10, digit * 10);
    return;
}

int main()
{
    cin >> n;
    memset(cnt, 0, sizeof(cnt));

    // n이 10이하인 경우 따로 체크 (무한루프 돌게 됨)
    if (n < 10)
    {
        for (int i = 1; i <= n; i++)
            cnt[i] += 1;
        for (int i = 0; i < 10; i++)
            cout << cnt[i] << ' ';
        return 0;
    }

    int len = to_string(n).size(); // n의 길이
    int A = (int)pow(10, len - 1); // A는 위에서 말한 것처럼

    // n=101 같은 경우, 99가 n보다 작은 수 중 1의 자리가 9인 것 중 가장 큰 수
    // 이런 경우는 따로 체크
    if (A > LastIsNine(n))
    {

        // 100...00 ~ n까지 계산
        for (int i = LastIsNine(n) + 1; i <= n; i++)
        {
            string s = to_string(i);
            for (int j = 0; j < s.size(); j++)
            {
                int idx = s[j] - '0';
                cnt[idx] += 1;
            }
        }

        // 나머지 부분 계산
        A /= 10;
        AtoB(A, LastIsNine(n), 1);
        while (1)
        {
            if (A == 1)
                break;
            AtoB(A / 10, A - 1, 1);
            A /= 10;
        }
    }

    // 위가 아닌 경우 그냥 계산
    else
    {
        AtoB(A, n, 1);
        while (1)
        {
            if (A == 1)
                break;
            AtoB(A / 10, A - 1, 1);
            A /= 10;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i] << ' ';
    }
}