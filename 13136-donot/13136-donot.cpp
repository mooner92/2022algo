#include <iostream>
using namespace std;
int main(){
    int h,w,tv;
    long long ans=0;
    cin >>h>>w>>tv;
    if(h%tv==0 && w%tv==0){
        cout <<((h/tv)*(w/tv));
        return 0;
    }

    ans = (h%tv!=0 && w%tv!=0) ? (((h/tv)+1)*((w/tv)+1)) : (h%tv!=0) ? (((h/tv)+1)*(w/tv)) : ((h/tv)*((w/tv)+1));
    cout << ans;
}