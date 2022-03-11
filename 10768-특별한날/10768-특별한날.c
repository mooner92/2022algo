#include<stdio.h>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	puts(a<2||(a==2&&b<18)?"Before":a==2&&b==18?"Special":"After");
	return 0;
}