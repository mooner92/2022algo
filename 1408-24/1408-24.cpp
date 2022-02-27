#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    char A[9];
    char B[9];
    cin >> A;
    cin >> B;
    int a_h,a_m,a_s,dummy1=0,dummy2=0,dummy3=0;
    dummy1 = (((A[0]*10)+A[1])*3600)+(((A[3]*10)+A[4])*60)+((A[6]*10)+A[7]);
    dummy2 = (((B[0]*10)+B[1])*3600)+(((B[3]*10)+B[4])*60)+((B[6]*10)+B[7]);
    dummy3 = dummy2 - dummy1;
    if(dummy3<0){
        dummy3+=(3600*24);
    }
    //cout << dummy3/3600 << (dummy3%3600)/60 << ((dummy3%3600)%60)%60;
    printf("%02d:%02d:%02d",dummy3/3600,(dummy3%3600)/60,((dummy3%3600)%60)%60);
}