#include<iostream>
using namespace std;

int K, N, ans;
int line[10001];
int  maxi = 0;
long long mid, high, low;

int main()
{
	cin >> K >> N;
	
	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (maxi < line[i]) maxi = line[i];
	}
	low = 1;
	high = maxi;
	ans = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;

		if (cnt >= N) {
			low = mid + 1;
			if (ans < mid) ans = mid;
		}
		else {// (cnt < N)
			high = mid - 1;
		}
	}
	
	cout << ans;
}