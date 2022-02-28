#include <iostream>
using namespace std;

int main(){
    int repeat,tmp=0,sum=0;
    cin >> repeat;
    int a[repeat];
    for(int i=0;i<repeat;i++){
        int k;
        cin >> a[i];
        if(a[i]==1){
            sum+=1+tmp;
            tmp+=1;    //tmp를 다음번 계산에 더해주는 추가점수 느낌으로 지정해줌
        }
        else if(a[i]==0){
            tmp=0;     //흐름 끊기면 초기화해줌
        }
    }
    cout << sum;
}