#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int M = 0;
	int i = 0;
	
	cin >> N;
	vector<int>card(N, 0);

	for (i = 0; i < N; ++i)
		cin >> card[i];

	cin >> M;
	sort(card.begin(), card.end());
	int num = 0;

	for (i = 0; i < M; ++i) {
		cin >> num;
		cout << upper_bound(card.begin(), card.end(), num)
			- lower_bound(card.begin(), card.end(), num) << " ";
	}		
}