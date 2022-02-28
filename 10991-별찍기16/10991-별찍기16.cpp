#include <iostream>
using namespace std;

int main(){
    int repeat;
    cin >> repeat;
    for(int i=0;i<repeat;i++){
        for(int k=repeat-(i+1);k>0;k--){
                cout <<" ";
            }
        for(int j=0;j<=i;j++){
            
            cout <<"*"<<" ";
        }
        cout <<endl;
    }
}