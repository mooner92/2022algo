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
/*
#include<stdio.h>
int main(){
    int n,f,temp,i;

    scanf("%d %d", &n, &f);

    n = (n/100) * 100;

    for(i = 0; i < 100; i++){
        temp = n;
        if( (temp+=i) % f==0)
            break;
    }

    if(i<10)
        printf("0");

        printf("%d", i);
}
*/