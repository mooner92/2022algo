#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template <size_t _Nw>
void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B)
{
    for (int i = 0, c = 0; i < _Nw; i++)
        c = _subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long *)&A._M_w[i]);
}
template <>
void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) { A._M_w -= B._M_w; }
template <size_t _Nb>
bitset<_Nb> &operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) { return _M_do_sub(A, B), A; }
template <size_t _Nb>
inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B)
{
    bitset<_Nb> C(A);
    return C -= B;
}

string a, b, ans;

template <size_t sz>
vector<int> _LCS(int l1, int r1, int l2, int r2, bool IsRev = 0)
{
    bitset<sz> D, x, S[26];
    if (!IsRev)
    {
        for (int i = l2; i <= r2; i++)
            S[b[i] - 'A'][i - l2] = 1;
        for (int i = l1; i <= r1; i++)
        {
            x = S[a[i] - 'A'] | D;
            D <<= 1, D[0] = 1;
            D = x & (x ^ (x - D));
        }
        vector<int> ret(r2 - l2 + 3);
        for (int i = l2; i <= r2; i++)
            ret[i - l2 + 1] = ret[i - l2] + D[i - l2];
        return ret;
    }
    else
    {
        for (int i = r2; i >= l2; i--)
            S[b[i] - 'A'][r2 - i] = 1;
        for (int i = r1; i >= l1; i--)
        {
            x = S[a[i] - 'A'] | D;
            D <<= 1, D[0] = 1;
            D = x & (x ^ (x - D));
        }
        vector<int> ret(r2 - l2 + 3);
        for (int i = r2; i >= l2; i--)
            ret[i - l2 + 1] = ret[i - l2 + 2] + D[r2 - i];
        return ret;
    }
}
vector<int> LCS(int l1, int r1, int l2, int r2, bool IsRev = 0)
{
    const int sz = r2 - l2 + 1;
    if (sz <= 64)
        return _LCS<64>(l1, r1, l2, r2, IsRev);
    if (sz <= 128)
        return _LCS<128>(l1, r1, l2, r2, IsRev);
    if (sz <= 256)
        return _LCS<256>(l1, r1, l2, r2, IsRev);
    if (sz <= 512)
        return _LCS<512>(l1, r1, l2, r2, IsRev);
    if (sz <= 1024)
        return _LCS<1024>(l1, r1, l2, r2, IsRev);
    if (sz <= 2048)
        return _LCS<2048>(l1, r1, l2, r2, IsRev);
    if (sz <= 4096)
        return _LCS<4096>(l1, r1, l2, r2, IsRev);
    if (sz <= 8192)
        return _LCS<8192>(l1, r1, l2, r2, IsRev);
    if (sz <= 16384)
        return _LCS<16384>(l1, r1, l2, r2, IsRev);
    if (sz <= 32767)
        return _LCS<32767>(l1, r1, l2, r2, IsRev);
    return _LCS<65536>(l1, r1, l2, r2, IsRev);
}
void Sol(int l1, int r1, int l2, int r2)
{
    if (l1 > r1)
        return;
    if (l1 == r1)
    {
        for (int i = l2; i <= r2; i++)
            if (b[i] == a[l1])
            {
                ans.push_back(b[i]);
                break;
            }
        return;
    }
    int mid = l1 + r1 >> 1;
    auto LCS1 = LCS(l1, mid, l2, r2, 0);
    auto LCS2 = LCS(mid + 1, r1, l2, r2, 1);
    int mx = -1, idx = 0;
    for (int i = l2; i <= r2 + 1; i++)
    {
        if (mx < LCS1[i - l2] + LCS2[i - l2 + 1])
            mx = LCS1[i - l2] + LCS2[i - l2 + 1], idx = i;
    }
    Sol(l1, mid, l2, idx - 1);
    Sol(mid + 1, r1, idx, r2);
}

int main()
{
    fastio;
    cin >> a >> b;
    Sol(0, a.size() - 1, 0, b.size() - 1);
    cout << ans.size() << '\n'
         << ans << '\n';
}