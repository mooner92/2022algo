#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <vector>
using namespace std;
const int MAX_N=100002;
const int MAX_INF=1e9;
typedef pair<int, int> Pii; // <dist, <start, end>>
int N, K, S1, S2;
int dist[MAX_N];
int left[MAX_N], right[MAX_N];
bool visited[MAX_N];
priority_queue<Pii, vector<Pii>, greater<Pii> > PQ;

int main() {
	scanf("%d%d", &N, &K);

	dist[1]=dist[N+1]=MAX_INF;
	right[1]=2;
	left[N+1]=N;
	PQ.push({MAX_INF, 1});
	PQ.push({MAX_INF, N+1});

	scanf("%d", &S1);
	for (int i=2; i<=N; i++) {
		scanf("%d", &S2);
		dist[i]=S2-S1;
		PQ.push({dist[i], i});
		left[i]=i-1;
		right[i]=i+1;
		S1=S2;
	}
	int ret=0;

	while (K--) {
		while (visited[PQ.top().second]) PQ.pop();
		int d = PQ.top().first;
		int idx = PQ.top().second;
		PQ.pop();
		ret += d;
		dist[idx] = dist[left[idx]] + dist[right[idx]] - dist[idx];
		PQ.push({dist[idx], idx});
		visited[left[idx]] = visited[right[idx]] = true;
		left[idx] = left[left[idx]];
		right[idx] = right[right[idx]];
		right[left[idx]] = idx;
		left[right[idx]] = idx;
	}
	printf("%d\n", ret);
	return 0;
}