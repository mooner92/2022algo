// #include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
int main()
{
    int n, k;
    vector<ll> arr;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        double tmp;
        cin >> tmp;
        arr[i] = (ll)(tmp * 1000);
    }
    sort(arr.begin(), arr.end());
    ll s = 0;
    for (int i = k; i + k < arr.size(); i++)
    {
        s += arr[i];
    }
    ll ans = s / (arr.size() - k - k) + 5;
    printf("%lld.%02lld\n", ans / 1000, ans % 1000 / 10);
    s = 0;

    s += k * arr[k];
    for (int i = k; i + k < arr.size(); i++)
    {
        s += arr[i];
    }
    s += k * arr[arr.size() - 1 - k];
    ans = s / arr.size() + 5;
    printf("%lld.%02lld\n", ans / 1000, ans % 1000 / 10);
}
