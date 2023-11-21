#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;

    int Z = floor(Y * 100 / X);
    int newZ = Z;
    int tosses = 0;

    while (Z == newZ && Z != 100)
    {
        X++;
        Y++;
        newZ = floor(Y * 100 / X);
        tosses++;
    }

    if (Z == 100)
    {
        cout << -1 << endl; // Z값이 이미 100%이므로 Z값은 절대 바뀌지 않음
    }
    else
    {
        cout << tosses << endl; // Z값이 바뀌는 동안 필요한 동전 던지기 횟수
    }

    return 0;
}

//////