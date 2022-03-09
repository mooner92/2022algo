#include <iostream>
using namespace std;
int main(){
    int a=0,b=0,plus,minus;
    cin >>plus>>minus;
    if((plus+minus)%2==1){
        cout << "-1";
        return 0;
    }
    a = (plus+minus)/2;
    b = plus-a;
    int tmp = max(a,b);
    b = min(a,b);
    cout << tmp<<" "<<b;
}