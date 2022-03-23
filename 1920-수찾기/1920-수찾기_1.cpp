#include<iostream>
#include<cstdio>
#include<algorithm>
 
using namespace std;
 
int arr[100001];
 
//이진탐색(Binary Search)을 이용하여 탐색
void Solution(int n, int key){
 
    int start = 0;
    int end = n-1;
    int mid;
 
    while(end - start >= 0){
        mid = (start + end)/2;
 
        if(arr[mid] == key){   //key 값이 배열의 중앙 값과 같을때
            printf("1\n");
            return ;
 
        }else if(arr[mid] > key) { //key 값이 배열의 중앙 값보다 작을때 (왼쪽으로)
            end = mid - 1;
 
        }else{  //key 값이 배열의 중앙 값보다 클때 (오른쪽으로)
            start = mid + 1;
        }
    }
 
    printf("0\n");
    return ;
}
 
int main(void){
 
    int n, m, tmp;
 
    //입력
    scanf("%d", &n);
 
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);   //quick sort를 이용해 배열 오름차순으로 정렬
 
    //입력
    scanf("%d", &m);
 
    for(int i=0; i<m; i++){
        scanf("%d", &tmp);
        Solution(n, tmp);
    }
 
    return 0;
}


//출처: https://blockdmask.tistory.com/166 [개발자 지망생]