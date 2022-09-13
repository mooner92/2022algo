// bool type INT_MAX배열을 선언하고 최소값 최대값이 나올때마다 갱신 후 배열의 minPivot과 maxPivot을 false로 ->
//정렬한 배열에 대한 인덱스를 맞춘 후 search & cout
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    vector<int> v1;
    bool visited[INT_MAX] = {
        0,
    };
    long long max = -1 * 1e9;
    long long min = 1e9;
    long long maxP = 0;
    long long minP = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    { //중복 빼고 다 담아줌
        cin >> k;
        if (!visited[k - 1])
        { // idx = k-1로 지정
            visited[k - 1] = true;
            v1.push_back(k);
        }
    }
    vector<int> v2(v1);
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
    {
    }

} ////