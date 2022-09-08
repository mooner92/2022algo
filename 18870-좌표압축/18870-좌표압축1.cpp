// bool type INT_MAX배열을 선언하고 최소값 최대값이 나올때마다 갱신 후 배열의 minPivot과 maxPivot을 false로 ->
//정렬한 배열에 대한 인덱스를 맞춘 후 search & cout
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    vector<int> v1;
    bool visited[INT_MAX] = {
        0,
    };
    long long max = -1 * 1e9;
    long long min = 1e9;
}