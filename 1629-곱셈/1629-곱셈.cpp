#include <iostream>
using namespace std;
using ll = long long;

ll mod(ll a,ll b,ll c){
    if(b==1) return a%c;  // b에 1이 들어오면 a%c를 리턴  (1인경우만 예외처리해줌)
    ll val = mod(a,b/2,c);  //재귀로 b를 계속 반으로 토막내줌 
    val = val*val%c;       //재귀의 마지막 항에서 이 줄에 걸려서 연쇄적인 리턴이 발생함
    if(b%2==0) return val; // b가 짝수면 val을 그대로 출력
    return val*a%c;         // b가 홀수면 계산해줌
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >>a>>b>>c;
    cout <<mod(a,b,c);
}