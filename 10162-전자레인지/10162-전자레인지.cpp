#include <iostream>
using namespace std;
int main(){
    int a,h=0,m=0,s=0;
    cin >> a;
    if(a%10!=0){
        cout << "-1";
        return 0;
    }
    while(1){
        if(a>=300){
            a-=300;
            h++;
        }
        if(a<300 && 60<=a){
            a-=60;
            m++;
        }
        if(a<60){
            s+=(a/10);
            break;
        }
    }
    cout <<h<<" "<<m<<" "<<s;

}   //swich case로 써야 빠른가?