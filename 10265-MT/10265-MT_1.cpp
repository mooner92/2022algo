#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int v, e, id;
int d[MAX];
int sccNum;  // scc 개수
int sn[MAX]; // i가 속한 SCC의 번호
vector<int> a[MAX];
bool finished[MAX]; // SCC 성립되면 true
stack<int> s;
vector<vector<int>> SCC;

int DFS(int c)
{
    d[c] = ++id; // 정점에 고유 id 할당
    s.push(c);   // 스택에 자신을 삽입

    int result = d[c];
    for (int next : a[c])
    {
        // 아직 방문하지 않은 정점이면
        if (d[next] == 0)
            result = min(result, DFS(next));
        // 방문은 했으나 아직 SCC로 성립하지 않은 정점이면
        else if (!finished[next])
            result = min(result, d[next]);
    }

    // 자신과 자신의 자식 정점들이 갈 수 있는 가장 높은 정점이 자신일 경우 SCC 추출
    if (result == d[c])
    {
        vector<int> scc;
        // 스택에서 자신이 나올 때까지 pop
        while (1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            sn[t] = sccNum;
            if (t == c)
                break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc); // SCC 추출
        sccNum++;
    }
    return result;
}

int main()
{

    // 그래프 정보 입력
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++)
    {
        int p, q;
        scanf("%d", &p);
        a[p].push_back(i);
    }
    // DFS를 수행하며 SCC 추출
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == 0)
            DFS(i);
    }
    // printf("%d\n", sccNum);
    sort(SCC.begin(), SCC.end());
    // 각 SCC 출력
    /*
    for (auto &currSCC : SCC)
    {
        for (int curr : currSCC)
            printf("%d ", curr);
        printf("-1 \n");
    }
    */

    for (auto &i : SCC)
    {
        if (i.size() <= e)
        {
            printf("%d", (int)i.size());
        }
    }
}
