#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a[4];
    for(int i=0;i<3;i++){
        int h;
        cin>>h;
        a[i] = h;
    }
    sort(a,a+4);
    if((a[1]+a[2]+a[3])!=180){     //왜 a[0]에는 1이 들어가는가?
        cout <<"Error";
        return 0;
    }
    if(a[1]==a[2] && a[2]==a[3]){
        cout << "Equilateral";
    }
    else if((a[1]+a[2]+a[3])==180 && (a[1]==a[2]) || a[2]==a[3]){
        cout <<"Isosceles";
    }
    else if((a[1]+a[2]+a[3])==180 && a[1]!=a[2]){
        cout <<"Scalene";
    }
}