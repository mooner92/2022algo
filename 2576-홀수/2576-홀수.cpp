#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector <int> a(7,101);
    int sum=0;
    for(int i=0;i<7;i++){
        int k=0;
        cin>>k;
        if(k%2==1){a.push_back(k); sum+=k;} //벡터에 홀수만 저장하고 sum에 +해줌
    }
    sort(a.begin(),a.end());
    if(a[0]==101){cout <<"-1"; return 0;}
    cout << sum <<"\n" << a[0];
}