#include <iostream>
using namespace std;
int main(){
    int q;
    cin>>q;
    q%=8;
    if(q==1){
        cout <<"1";
    }
    else if(q==2 || q==0){
        cout<<"2";
    }
    else if(q==3 || q==7){
        cout<<"3";
    }
    else if(q==4 || q==6){
        cout<<"4";
    }
    else if(q==5){
        cout<<"5";
    }

}