#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    //printf("%d",s[0]);   정수형으로 잘 나오나 확인함 0 = 48
    int q1,q2,a;
    q1 = s[0]-48;
    q2 = s[4]-48;
    a = s[8]-48;
    if(q1+q2==a){
        cout <<"YES";
    }
    else cout<<"NO";

}