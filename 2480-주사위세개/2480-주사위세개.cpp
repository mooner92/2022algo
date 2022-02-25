#include <iostream>
using namespace std;

int main(){
    int a,b,c,m1,m2;
    cin >>a>>b>>c;
    m1=max(a,b);
    m2=max(m1,c);
    if(a==b&&b==c){cout << 10000+(a*1000);}
    else if(a==b&&b!=c){cout << 1000+(a*100);}
    else if(a!=b&&b==c){cout << 1000+(b*100);}
    else if(a!=b&&b!=c&&a==c){cout << 1000+(a*100);}
    else if(a!=b&&b!=c){cout << m2*100;}
    
}