#include <iostream>
using namespace std;

int main(){
    int correct;
    cin>>correct;
    int sum=0;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        if(a==correct){
            sum++;
        }
    }
    cout <<sum;
}