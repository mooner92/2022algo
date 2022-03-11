#include <iostream>
using namespace std;
int main(){
    int a,b,tmp=0;
    cin >>a>>b;
    tmp = (a>2) ? tmp+=1 : (a==2) ? tmp+=2 : (a<2) ? tmp+=3 : 1;
    //a가 2보다 크면 1 같으면 2 작으면 3 반환 b까지 한번에 계산해주기


}