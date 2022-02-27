#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[9];
    int sum=0;
    for(int i=0;i<9;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int num1,num2;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i!=j){
                int stan = a[i]+a[j];
                if(sum-stan==100){
                    num1=i;
                    num2=j;
                }

            }
        }
    }
    a[num1] = 101;
    a[num2] = 101;
    sort(a,a+9);
    for(int i=0;i<7;i++){
        cout << a[i] <<endl;
    }

    
}