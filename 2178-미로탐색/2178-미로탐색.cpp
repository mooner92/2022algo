#include <iostream>
#include <vector>
//#include <climits>
using namespace std;

const int arrow[8] = {
    -1,
    0,
    0,
    1,
    1,
    0,
    0,
    -1
}; //0,1 = 상   2,3 = 우    4,5 = 하    6,7 = 좌
bool visited[102][102] = {0,};
int ds[102][102] = {0,};
int n, m;
int cnt = 0;
int dist=INT_MAX;
int dfs(int k, int l)  //종착지에 도착했거나 visited가 1인경우 널리턴
{
    cnt++;
    if (k == n && l == m)
    {
        cnt < dist ? (dist = cnt) : 0;

        cnt = 0;
            return 0;
    }

    else if(!visited[k][l]){ //wrong_path에서 true로 바꿔놓은 visited때문에 right_path의 진입이 막히는 상황(?) X
        visited[k][l] = 1;
    }
    /*
    else if(!ds[k][l])
        return 0;  //1인것만 dfs하면 이 조건은 필요 X
    */
        for (int i = 0; i < 4;i++){
            if(ds[k+arrow[2*i]][l+arrow[(2*i)+1]] && !visited[k + arrow[2 * i]][l + arrow[(2 * i) + 1]]){  //상하좌우 계산 , 방문하려는 visited가 false일 때 실행
                //visited[k + arrow[2 * i]][l + arrow[(2 * i) + 1]] = 1;
                return dfs(k + arrow[2 * i], l + arrow[(2 * i) + 1]);
            }
        }
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> c;
            ds[i][j] = c - 48;
        }
    }
    dfs(1, 1);
    cout << dist;
}

/*
방법
0,0에서 n,m까지 도달한 것들만 return 하여 배열에 저장 -> n,m은 무조건 맨 오른쪽 아래이므로 도달할 수 있는 방향은 두 가지
위,왼쪽에서 오는 경우임 두 경우의 값을 저장할 정수배열 지정 후 최솟값 출력
*/