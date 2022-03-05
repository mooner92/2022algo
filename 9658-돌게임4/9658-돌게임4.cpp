#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int n;
	int DP[1010];
 
	cin >> n;
 
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 0;
	DP[4] = 1;
	
	for (int i = 5; i <= n; ++i) {
		if (min({ DP[i - 1], DP[i - 3], DP[i - 4] }) == 1) {
			DP[i] = 0;
		}
		else {
			DP[i] = 1;
		}
	}
	
	if (DP[n] == 1) {
		cout << "SK" << endl;
	}
	else {
		cout << "CY" << endl;
	}
	return 0;
}