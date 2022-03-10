#include <iostream>
#include <vector>
using namespace std;
int main(){
    for(int i=0;i<3;i++)
    {   vector<int> a;
        int h,m,s;
        for(int j=0;j<6;j++){
            int k;
            cin >>k;
            a.push_back(k);
        }  //배열에 저장
        if(a[5]<a[2]){
            a[4]-=1;
            a[5]+=60;
        }
        if(a[4]<a[1]){
            a[3]-=1;
            a[4]+=60;
        }
        cout << a[3]-a[0]<<" "<<a[4]-a[1]<<" "<<a[5]-a[2]<<endl;
    }


}