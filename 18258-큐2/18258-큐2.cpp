#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
using ll= long long;
int main() {

	queue<int> q;

	ll n;
	scanf("%lld", &n);

	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			scanf("%d", &x);
			q.push(x);
		}
		else if (s == "pop") {
			int front = -1;
			if (!q.empty()) {
				front = q.front();
				q.pop();
			}
			printf("%d\n", front);
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			int empty = 0;
			if (q.empty()) {
				empty = 1;
			}
			printf("%d\n", empty);
		}
		else if (s == "front") {
			int front = -1;
			if (!q.empty()) {
				front = q.front();
			}
			printf("%d\n", front);
		}
		else if (s == "back") {
			int back = -1;
			if (!q.empty()) {
				back = q.back();
			}
			printf("%d\n", back);
		}

	}
	return 0;
}