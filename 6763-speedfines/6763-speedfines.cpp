#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >>a>>b;
    if((b-a)>=1 && (b-a)<=20){
        cout <<"You are speeding and your fine is $100."<<endl;
    }
    else if((b-a)>=21 && (b-a)<=30){
        cout <<"You are speeding and your fine is $270."<<endl;
    }
    else if((b-a)>=31){
        cout <<"You are speeding and your fine is $500."<<endl;
    }
    else if((b-a)<=0){
        cout <<"Congratulations, you are within the speed limit!"<<endl;
    }
}