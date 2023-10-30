#include <iostream>
using namespace std;

long long tile[1000] = {0};

long long Tile(int n)
{
    if (n == 1)
        return tile[n] = 1;
    else if (n == 2)
        return tile[n] = 2;
    if (tile[n] != 0)
        return tile[n];
    return tile[n] = Tile(n - 1) + Tile(n - 2);
}
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        printf("%d : %lld\n", i, Tile(i));
    }
}