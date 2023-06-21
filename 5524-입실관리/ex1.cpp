#include <iostream>
using namespace std;
int main()
{
    int n[102] = {0};
    for (int i = 0; i < 100; i++)
    {
        n[i] = 7 * i;
    }
    for (int f : n)
    {
        cout << f << " " << f - 1 << '\n';
    }
}
/////////
