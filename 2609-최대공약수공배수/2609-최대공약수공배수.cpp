#include <iostream>
using namespace std;

int gcd(int a,int b){
    while(b!=0){  //a항을 1로 나눴을 때 나머지가 0이 되므로 b가 0이되면 정리가 끝났다는 뜻임
        int r=a%b;
        a=b;
        b=r;
        //tmp 위치 바꾸기 하듯이
    }
    return a;
}
int lcm(int a,int b,int c){
    return a*b/c;
}
int main(){
    int a,b,c,d;
    cin>>a>>b;
    c = gcd(a,b);
    d = lcm(a,b,c);
    cout <<c<<" "<<d;
}