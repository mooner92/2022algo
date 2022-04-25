#include <iostream>
using namespace std;

int main()
{
    int num[10000] = {
        1,
    };
    int temp;

    for (int i = 0; i < 10000; i++)
    {
        if (i < 10)
            num[i + i] = 1;
        else if (i < 100)
            num[i + i / 10 + i % 10] = 1;
        else if (i < 1000)
            num[i + i / 100 + i % 100 / 10 + i % 10] = 1;
        else if (i < 10000)
        {
            temp = i + i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10;
            if (temp < 10000)
                num[temp] = 1;
        }
    }
    for (int i = 1; i < 10000; i++)
    {
        if (!num[i])
            cout << i << endl;
    }
}