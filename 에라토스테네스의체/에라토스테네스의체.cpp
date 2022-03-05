#include<stdio.h>
#include<math.h>

int main(void)

{
	int num;
	int cnt = 0;
	int arr[10000];
	scanf("%d", &num);

	for (int i = 2; i <= num; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i < sqrt(num); i++)
	{
		if (arr[i] == 0) continue;    // 0이면 건너뛰고 아니면 실행
		for (int j = 2 * i; j <= num; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= num; i++)
	{
		if (arr[i] != 0) printf("%d ", arr[i]);
	}


}