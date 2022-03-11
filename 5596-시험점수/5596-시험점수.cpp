#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,d,sum1=0,sum2=0;
    cin>>a>>b>>c>>d;
    sum1+=a+b+c+d;
    cin>>a>>b>>c>>d;
    sum2+=a+b+c+d;
    cout << max(sum1,sum2);
}