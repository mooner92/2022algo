#include <iostream>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
        int a,b,c,room=0;
        cin>>a>>b>>c;
        if(c%a==0){
            room+=(a*100);  //100의자리 정하기
            room+=(c/a);
        }
        else if(c%a!=0){
            room+=((c%a)*100);   //100의자리 정하기
            room+=((c/a)+1);
        }
        cout <<room<<endl;
    }
}