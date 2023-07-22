#include <iostream>
#include <vector>
#include <algorithm>

int optimal_magic_moves(int n, std::vector<int> &capitals)
{
    int moves = 0;
    while (std::any_of(capitals.begin(), capitals.end(), [](int x)
                       { return x < 0; }))
    {
        for (int i = 0; i < n; ++i)
        {
            if (capitals[i] < 0)
            {
                moves++;
                capitals[(i - 1 + n) % n] -= std::abs(capitals[i]);
                capitals[(i + 1) % n] -= std::abs(capitals[i]);
                capitals[i] = std::abs(capitals[i]);
            }
        }
    }
    return moves;
}

int main()
{
    int n, k;
    std::cin >> n;
    std::vector<int> capitals;
    for (int i = 0; i < n; i++)
    {
        std::cin >> k;
        capitals.push_back(k);
    }

    std::cout << optimal_magic_moves(n, capitals) << std::endl;

    return 0;
}
