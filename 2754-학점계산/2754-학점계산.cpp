#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    double sum=0;
    char k = s[0],k1 = s[1];
    k=='A' ? sum+=4.0 : k=='B' ? sum+=3.0 : k=='C' ? sum+=2.0 : k=='D' ? sum+=1.0 : k=='F' ? sum+=0.0 : 1;
    k1=='+' ? sum+=0.3 : k1=='0' ? 1 : k1=='-' ? sum-=0.3 : 1;

    printf("%.1f",sum);

}

// C언어를 사용하여 4.0을 printf("%d%s%d",A,".",B);로 나타낼 수도 있음