#include <stdio.h>

int main() {
	int t, arr[]={25, 10, 5, 1}, count[4] = {0,};
	int c;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &c);
		for(int j=0; j<4; j++) {
			while(c >= arr[j]) {
				c -= arr[j];
				count[j] ++;
			}
			if(c == 0) {
				break;
			}
		}
		for(int j=0; j<4; j++) {
			printf("%d ", count[j]);
			count[j] = 0;
		}
		printf("\n");
	}
}