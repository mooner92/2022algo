#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, N;
vector<int> v;

int main()
{
	cin >> L;
	for (int i = 0; i < L; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> N;

	sort(v.begin(), v.end());

	int lo = 0, hi = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > N) {
			if (i == 0)
				lo = 1;
			else
				lo = v[i - 1] + 1;
			hi = v[i] - 1;
			break;
		}
		else if (v[i] == N) {
			lo = hi = 0;
			break;
		}
	}
	if (hi == 0 && lo == 0) cout << 0;
	else cout << (N - lo) * (hi - N + 1) + (hi - N);
}