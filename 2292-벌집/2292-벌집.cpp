#include <iostream>
using namespace std;
int main(){
    int k,stan=1,sum=2;
    cin>>k;
    if(k==1){
            cout <<"1";
            return 0;
        }
    for(int i=0;i<1000000;i++){
        
        if(sum>k){
            cout << stan;
            break;
        }
        stan++;
        sum+=(6*(i+1));

    }
}