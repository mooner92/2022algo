#include <iostream>
using namespace std;
int main(){
    int a,b,tmp=0;
    cin >>a>>b;
    if(a>2){
        cout << "After";
    }
    if(a==2){
        if(b>18){
            cout << "After";
        }
        else if(b==18){
            cout<<"Special";
        }
        else if(b<18){
            cout<<"Before";
        }
    }
    if(a<2){
        cout<<"Before";
    }
    
}