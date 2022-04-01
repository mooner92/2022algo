#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 987654321

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long min, max;
	cin >> min >> max;

	long long ans = max - min + 1; // 살펴봐야 하는 숫자의 갯수

	vector<bool> sieve(max - min + 1, false);
	long long i = 2; // 처음 제곱수는 2*2 이므로 i=2로 초기화

    	// 제곱수가 max보다 작거나 같을 때만 진행
	while (i * i <= max) {

		// 처음으로 i*i로 나누어떨어지는 수를 찾아야 한다.
        		// 위에서 설명한 !구하려는 수! 를 구하기 위한 과정
		long long sNum = min / (i * i);
		if (min % (i * i) != 0)
            			sNum += 1;

        		// (!구하려는 수!는 1씩 증가시키고) * 제곱수 인 모든 인덱스에 true 표시하기
		while (sNum * (i * i) <= max) {
			if (sieve[sNum * (i * i) - min] == false) {
				sieve[sNum * (i * i) - min] = true;
				ans -= 1;
                			// true로 표시하는 과정은 모두 나누어 떨어지는 숫자이므로,
                			// 살펴봐야 하는 숫자의 총 갯수에서 1개씩 빼주면 된다.
			}
			sNum += 1;
		}
		i += 1; // 다음 제곱수로 넘어가기 위해 i를 1 증가시키기
	}

	cout << ans; // 제곱수로 나누어 떨어지지 않는 갯수가 된다.
	return 0;
}