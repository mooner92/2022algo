#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, f, p;
    priority_queue<int> pq;
    scanf("%d %d", &n, &f);
    for (int i = 1; i < 10; i++)
    {
        p = f * i;
        pq.push((n - (n % p)) % 100 * (-1));
    }
    printf("%02d", pq.top() * (-1));
}