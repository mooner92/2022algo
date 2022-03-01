#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){    //0부터 시작으로 설정했기 때문에
        if((i+2)%2==0){   //홀수일때
            for(int j=0;j<n;j++){
                cout <<"*"<<" ";
            }
            cout <<endl;
        }
        else if((i+2)%2==1){  //짝수일때
            for(int j=0;j<n;j++){
                cout <<" " << "*";
            }
            cout <<endl;

        }
    }
}