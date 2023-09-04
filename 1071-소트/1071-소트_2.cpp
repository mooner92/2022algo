#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] + 1 == v[i + 1])
        { // 현재 값과 다음 값이 1 차이일 때
            int end = i + 2;
            while (end < n && v[end] == v[i + 1])
            { // 같은 값이 연속으로 나올 때까지 end 증가
                end++;
            }

            if (end == n)
            { // 끝까지 같은 값이 연속으로 나오는 경우
                int start = i - 1;
                while (start >= 0 && v[start] == v[i])
                { // 이전 값이 같은 경우를 찾아서
                    start--;
                }

                v[start + 1]++; // 이전 값 하나 증가
                v[i + 1]--;     // 현재 값 하나 감소
            }
            else
            {                           // 끝까지 같은 값이 연속으로 나오지 않는 경우
                swap(v[end], v[i + 1]); // end와 현재 값을 교환
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}

/////