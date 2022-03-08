#include <iostream>
using namespace std;
int main(){
    int k[9],stan=0;
    for(int i=0;i<8;i++){
        int a;
        cin>>a;
        k[i] = a;
        if(i>0){
            if(k[i]==(k[i-1]+1)){
                stan++;
            }
            else if(k[i]==(k[i-1]-1)){
                stan+=0;
            }
            else if(k[i]!=(k[i-1]-1) || k[i]==(k[i-1]+1)){
                cout << "mixed";
                //break;
                return 0;
            }
        }
    }
    if(stan!=0){
        cout <<"ascending";
    }
    else if(stan==0){
        cout << "descending";
    }
}