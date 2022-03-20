#include <iostream>
using namespace std;
int main(){
    int q;
    int d=2;
    cin>>q;
    if(q!=1){
        while(q>1){
            if(q%d==0){
                cout << d<<"\n";
                q/=d;
            }
            else
                d++;
        }
    }
}