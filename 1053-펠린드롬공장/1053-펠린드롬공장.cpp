#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int answer;
string input;
int dp[50][50];
int solve(int left, int right) {
	if (dp[left][right] != -1) return dp[left][right];
	if (left >= right) return 0;
	dp[left][right] = min({  solve(left + 1, right) + 1, solve(left, right - 1) + 1 , solve(left+1, right-1)+(input[left]!=input[right])});
	return dp[left][right];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> input;
	
	memset(dp, -1, sizeof(dp));
	answer = solve(0, input.length() - 1);

	for (int i = 0; i < input.length() - 1; i++) {
		for (int j = i + 1; j < input.length(); j++) {
			memset(dp, -1, sizeof(dp));
			swap(input[i], input[j]);
			answer = min(answer, solve(0, input.length() - 1)+1);
			swap(input[i], input[j]);
		}
	}

	cout << answer;

	return 0;
}