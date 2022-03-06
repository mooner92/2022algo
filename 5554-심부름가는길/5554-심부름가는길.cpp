#include <iostream>
using namespace std;

int main(){
    int sum=0;
    for(int i=0;i<4;i++){
        int l;
        cin >>l;
        sum+=l;
    }
    cout <<sum/60 <<"\n"<< sum%60;

}