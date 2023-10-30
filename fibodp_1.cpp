#include <iostream>
using namespace std;
int fibodp(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibodp(n - 1) + fibodp(n - 2);
}
int main()
{
    for (int i = 1; i <= 20; i++)
    {
        printf("%d항 : %d\n", i, fibodp(i));
    }
}