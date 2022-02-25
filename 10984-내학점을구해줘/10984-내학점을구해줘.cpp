#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int repeat;
    cin >>repeat;
    for(int i=0;i<repeat;i++){
        int repeat1,gpa1=0;
        double gpa2=0.0;
        cin >> repeat1;
        for(int i=0;i<repeat1;i++){
            int a;
            double b;
            cin >> a >> b;
            gpa1+=a;
            gpa2+=a*b;
        }
        double ave = gpa2/gpa1;
        printf("\n%d ",gpa1);
        printf("%.1f\n",ave);
    }
}