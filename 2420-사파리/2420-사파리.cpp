#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    cout << abs(a-b);  //오버플로남 -2억,2억일때   범위를 보니 longlong으로 해결이 가능할 것 같았음
}