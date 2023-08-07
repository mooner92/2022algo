#include <iostream>
using namespace std;
int main()
{
    long long X, Y;
    cin >> X >> Y;

    long long Z = (Y * 100) / X;
    if (Z >= 99)
    {
        cout << -1 << "\n";
    }
    else
    {
        // 이항분포 사용해서 최소 횟수 도출
        long long left = 0, right = X;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            long long new_Z = ((Y + mid) * 100) / (X + mid);
            if (new_Z == Z)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        cout << left << "\n";
    }

    return 0;
}

//
