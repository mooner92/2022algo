#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m,n,min,sum=0,dummy1;
    cin >>m>>n;
    dummy1=m;
    m=sqrt(m);
    n=sqrt(n);
    if(m==n){cout <<"-1"; return 0;}
    if(pow(m,2)!=dummy1){       //m이 완전제곱수일 경우의 예외처리를 안해줘서 틀림  sqrt(m)과 dummy1을 비교하여 처음받은 m이 완전제곱수인지 확인해줌.
        m++;
    }
    for(int i=m;i<=n;i++){
        if(i==m)min=pow(m,2);
        sum+=pow(i,2);
    }
    cout << sum <<"\n"<<min<<endl;
}