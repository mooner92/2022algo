#include <iostream>
#include <stdio.h>
using namespace std;
//int v[1001];
int main(){
    int r;
    cin >> r;
    for(int i=0;i<r;i++){
        double stu,sum=0,sup=0;
        double avg,per;
        cin >> stu;
        int k[1001] = {0};
        for(int j=0;j<stu;j++){
            int score;
            cin >> score;
            k[j] = score;
            sum+=score;
        }
        avg = sum/stu;
        for(int h=0;h<stu;h++){
            if(k[h]>avg)sup++;
        }
        //per = sup*100/stu;
        printf("%.3f%s\n",sup*100/stu,"%");
    }

}