#include <iostream>
using namespace std;
int main(){
    int repeat=1;
    while(repeat!=-1){
        cin >> repeat;
        int sum=0,stan=0;
        for(int i=0;i<repeat;i++){
            int a,b;
            cin>>a>>b;
            sum+=(a*(b-stan));
            stan=b;
        }
        if(repeat==-1) break;
        cout << sum << "miles"<<endl;

    }
}