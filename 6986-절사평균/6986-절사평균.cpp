#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

float k1(deque<float> d, int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        d.pop_front();
        d.pop_back();
    }
    float sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        sum += d[i];
    }
    return sum / d.size();
}

float k2(deque<float> d, int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        d[i] = d[k];
        d[d.size() - i - 1] = d[d.size() - k - 1];
    }
    float sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        sum += d[i];
    }
    return sum / d.size();
}

float round_digit(float num, int d)
{
    float t = pow(10, d - 1);
    return round(num * t) / t;
}

int main()
{
    int n, k;
    cin >> n >> k;
    deque<float> d1;
    for (int i = 0; i < n; i++)
    {
        float a;
        cin >> a;
        d1.push_back(a);
    }
    sort(d1.begin(), d1.end());
    // cout << d1.front();
    cout << round_digit(k1(d1, n, k), 3) << "\n";
    cout << round_digit(k2(d1, n, k), 3);
}
//절사 구하기
