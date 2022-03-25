#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testn;
	int n, m;
	int importance;
	int count;

	scanf("%d", &testn);

	for (int i = 0; i < testn; i++) {
		count = 0;
		scanf("%d %d", &n, &m);
		
		priority_queue<int> pq; // 내림차순 정렬해야 pop할 때 높은게 빠져나옴.
		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) {
			scanf("%d", &importance);
			q.push({ j, importance });
			pq.push(importance);
		}

		while (!q.empty()) {
			// 위치값과, 우선순위 값을 가져온 뒤 pop수행
			int location = q.front().first;
			int value = q.front().second;
			q.pop();
            
			// 값 비교
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (m == location) {
					printf("%d\n", count);
					break;
				}
			}

			else q.push({ location, value });
		}
	}

	return 0;
}