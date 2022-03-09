#include <iostream>
#include <stdio.h>
using namespace std;
int Factorial(int n) {
	if (n == 1)
		return 1;
	else
		return Factorial(n - 1) * n;
}  //팩토리얼을 구하는 함수      ###재귀라 시간이 오래걸림###

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int b = Factorial(n)/(Factorial(k)*Factorial(n-k));
    printf("%d",b);
}