#include <cstdio>
#include <vector>
using namespace std;
long long sum(vector<long long> &tree, int i)
{
    long long ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long> &tree, int i, long long diff)
{
    while (i < tree.size())
    {
        tree[i] += diff;
        i += (i & -i);
    }
}
int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> a(n + 1);
    vector<long long> tree(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        update(tree, i, a[i]);
    }
    m += k;
    while (m--)
    {
        int t1;
        scanf("%d", &t1);
        if (t1 == 1)
        {
            int t2;
            long long t3;
            scanf("%d %lld", &t2, &t3);
            long long diff = t3 - a[t2];
            a[t2] = t3;
            update(tree, t2, diff);
        }
        else
        {
            int t2, t3;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1));
        }
    }
    return 0;
}