#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,k,sum=0;
    cin >> n>>k;
    int array[2*n];
    for(int i=0;i<n;i++){
        int k;
        cin >>k;
        array[i]=k;
        array[i+n]=k;    //배열 두개를 이은 배열을 생성 ex:) [1,2,3,4] ===>> [1,2,3,4,1,2,3,4]

    
    cout << sum;
}