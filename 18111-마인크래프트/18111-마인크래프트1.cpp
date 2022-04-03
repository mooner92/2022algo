#include <iostream>
#include <limits.h>
using namespace std;
int main() {
    int n, m, b;
    int map[500][500];
    int leastTime = INT_MAX;
    int mostHeight;
    cin >> n >> m >> b;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];

	for (int h = 0; h <= 256; h++) {
		int build = 0;
		int remove = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int height = map[i][j] - h;
				if (height > 0) remove += height;
				else if (height < 0) build -= height;
			}
		}
		//지울것 + 인벤토리 블록 >= 채울것
		if (remove + b >= build) {
			int time = remove * 2 + build;   //배열 전부 계산해준 뒤 시간 매번 계산해줌
			if (leastTime >= time) {
				leastTime = time;
				mostHeight = h;
			}
		}
	}
    cout << leastTime << ' ' << mostHeight <<'\n';
}