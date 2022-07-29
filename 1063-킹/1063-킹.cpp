#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int cb[8][8] = {0}; // king=2 stone=1 blank=0

    int x1, x2, y1, y2, n; // stone is 2 act
    string s1, s2;
    cin >> s1 >> s2 >> n;
    // getline(cin, s1);
    x1 = s1[0] - 65; // alpha
    x2 = s2[0] - 65; // alpha
    y1 = s1[1] - 49; // A1 = 0,0
    y2 = s2[1] - 49;
    pair<int, int> king;
    pair<int, int> stone;
    king = make_pair(x1, y1);
    stone = make_pair(x2, y2);
    // cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << n;
    //여기까지 잘됨
    for (int i = 0; i < n; i++) // standard for king loop
    {
        string s;
        cin >> s;
        if (s == "R")
        {
            king.first++;
            if (king == stone && stone.first == 7)
            {
                king.first--;
            }
            else if (king == stone)
            {
                stone.first++;
            }
            else if (king.first == 8)
            {
                king.first--;
            }
        }
        else if (s == "L")
        {
            king.first--;
            if (king == stone && stone.first == 0)
            {
                king.first++;
            }
            else if (king == stone)
            {
                stone.first--;
            }
            else if (king.first == -1)
            {
                king.first++;
            }
        }
        else if (s == "B")
        {
            king.second--;
            if (king == stone && stone.second == 0)
            {
                king.second++;
            }
            else if (king == stone)
            {
                stone.second--;
            }
            else if (king.second == -1)
            {
                king.second++;
            }
        }
        else if (s == "T")
        {
            king.second++;
            if (king == stone && stone.second == 7)
            {
                king.second--;
            }
            else if (king == stone)
            {
                stone.second++;
            }
            else if (king.second == 8)
            {
                king.second--;
            }
        }
        else if (s == "RT")
        {
            king.first++;
            king.second++;
            if (king == stone && (stone.first == 7 || stone.second == 7))
            {
                king.first--;
                king.second--;
            }
            else if (king == stone)
            {
                stone.first++;
                stone.second++;
            }
            else if (king.first == 8 || king.second == 8)
            {
                king.first--;
                king.second--;
            }
        }
        else if (s == "LT")
        {
            king.first--;
            king.second++;
            if (king == stone && (stone.first == 0 || stone.second == 7))
            {
                king.first++;
                king.second--;
            }
            else if (king == stone)
            {
                stone.first--;
                stone.second++;
            }
            else if (king.first == -1 || king.second == 8)
            {
                king.first++;
                king.second--;
            }
        }
        else if (s == "RB")
        {
            king.first++;
            king.second--;
            if (king == stone && (stone.first == 7 || stone.second == 0))
            {
                king.first--;
                king.second++;
            }
            else if (king == stone)
            {
                stone.first++;
                stone.second--;
            }
            else if (king.first == 8 || king.second == -1)
            {
                king.first--;
                king.second++;
            }
        }
        else if (s == "LB")
        {
            king.first--;
            king.second--;
            if (king == stone && (stone.first == 0 || stone.second == 0))
            {
                king.first++;
                king.second++;
            }
            else if (king == stone)
            {
                stone.first--;
                stone.second--;
            }
            else if (king.first == -1 || king.second == -1)
            {
                king.first++;
                king.second++;
            }
        }
    }
    cout << char(king.first + 65) << king.second + 1 << "\n"
         << char(stone.first + 65) << stone.second + 1;
}