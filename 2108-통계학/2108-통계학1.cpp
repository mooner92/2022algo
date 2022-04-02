#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int coordinate[500001];
int cnt[8001];
int N, a, b, c, d;
int sum = 0;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coordinate[i];
		sum += coordinate[i];
		cnt[coordinate[i]+4000]++;
	}
	
	sort(coordinate, coordinate + N);
	
	int flag;
	int max = 0;
	
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i < 8001; i++)
	{
		if (cnt[i] == max)
		{
			flag = i;
			break;
		}
	}

	a = round(double(sum) / N);
	b = coordinate[(N - 1) / 2];
	c = flag - 4000;
	d = coordinate[N - 1] - coordinate[0];

	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << d << "\n";
}