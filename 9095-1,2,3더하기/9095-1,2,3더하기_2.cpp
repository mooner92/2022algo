#include <iostream>
int main()
{
    int n, k;
    int ds[11] = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
    std::cin >> n;
    while (n--)
    {
        std::cin >> k;
        std::cout << ds[k - 1] << "\n";
    }
}