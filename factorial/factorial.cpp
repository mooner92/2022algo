#include <iostream>
#include <stdio.h>
using namespace std;
int Factorial(int n) {
	if (n == 1)
		return 1;
	else
		return Factorial(n - 1) * n;
}  //팩토리얼을 구하는 함수

int factorial(int t) {
    int ans = 1;
    for (int i = t; i > 0; i--) {
        ans *= i;
    }
    return ans;
}
