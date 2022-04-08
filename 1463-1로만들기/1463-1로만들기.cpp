#include <iostream>
using namespace std;
int main()
{
    int cnt = 0;
    int N;
    cin >> N;
    while (1)
    {
        if (N % 3 == 0)
        {
            cnt++;
            N /= 3;
        }

        else if (((N - 1) % 3 != 0 && N % 2 == 0) || (N % 2 == 0 && (N / 2) % 2 == 0))
        {
            cnt++;
            N /= 2;
        }
        else if (N == 1)
        {
            break;
        }
        else
        {
            N -= 1;
            cnt++;
        }
    }
    cout << cnt;
}