#include <stdio.h>
 
long long tree[1000001];
 
int main(void){
 
    long long M, N;
    long long max = 0;
    long long left, right;
    long long result = 0;
    scanf("%lld %lld", &N, &M);
 
    for (int i = 0; i < N; i++){
        scanf("%lld", &tree[i]);
        if (max < tree[i])
            max = tree[i];
    }
    left = 0; right = max;
 
    while (left <= right){
        long long mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < N; i++)
            if (mid < tree[i])
                total += tree[i]-mid;
 
        if (total >= M){
            if (result<mid)
                result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
 
    }
 
    printf("%lld\n", result);
 
    return 0;
}