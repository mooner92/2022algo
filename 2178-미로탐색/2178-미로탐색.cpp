#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int arrow[8] = {
    -1,
    0,
    0,
    -1,
    1,
    0,
    0,
    1
}; //0,1 = 상   2,3 = 좌    4,5 = 하    6,7 = 우
bool visited[101][101];
int ds[101][101];
int n, m;
int cnt = 0;
int dist[2];
int dfs(int k, int l)
{
    cnt++;
    if (k == n && l == m)
    {
        if(dist[0]){
            dist[1] = cnt;
        }
        else
        dist[1] = cnt;

        cnt = 0;
            return 0;
    }
    else if(!ds[k][l])
        return 0;  //1인것만 dfs하면 이 조건은 필요 X
    else
    {
        for (int i = 0; i < 4;i++){
            if(ds[k+arrow[2*i]][l+arrow[(2*i)+1]]){  //상하좌우 계산
                return dfs(k+arrow[2*i],l+arrow[(2*i)+1]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> ds[i][j];
        }
    }
    dfs(0, 0);
    cout << min(dist[0], dist[1]);
}

/*
방법
0,0에서 n,m까지 도달한 것들만 return 하여 배열에 저장 -> n,m은 무조건 맨 오른쪽 아래이므로 도달할 수 있는 방향은 두 가지
위,왼쪽에서 오는 경우임 두 경우의 값을 저장할 정수배열 지정 후 최솟값 출력
*/