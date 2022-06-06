#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
}

int search(int s)
{
    int cnt = 0;
    while (s != 1)
    {
        if (s % 3 == 0)
        {
            s /= 3;
            cnt++;
        }
        // else if ()
    }
}