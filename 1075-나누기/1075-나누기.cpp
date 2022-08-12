#include <iostream>
#include <queue>
#include <vector>
//#include <stdio.h>
int main()
{
    int n, f, p;
    priority_queue<int> pq;
    vector<int> v;
    scanf("%d %d", &n, &f);
    for (int i = 1; i < 10; i++)
    {
        p = f * i;
        pq.push((n % p) * (-1));
    }
    printf("%02d", pq.top() * (-1));
}