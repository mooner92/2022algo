#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int q, w;
        cin >> q, w;
        q %= 10;
        if (q == 2 || q == 3 || q == 7 || q == 8)
        {
            switch (w % 4) // 4항계산
            {
            case 1:
                cout << q << endl;
                break;
            case 2:
                if (q == 2 || q == 8)
                    cout << 4 << endl;
                else if (q == 3 || q == 7)
                    cout << 9 << endl;
                break;
            case 3:
                int k;
                (q == 2) ? k = 8 : (q == 3) ? k = 7
                               : (q == 7)   ? k = 3
                               : (q == 8)   ? k = 2
                                            : true;
                cout << k << endl;
                break;
            case 0:
                int j;
                (q == 2 || 1 == 8) ? j = 6 : (q == 3 || q == 7) ? j = 1
                                                                : true;
                cout << j << endl;
                break;
            default:
                break;
            }
        }
        else if (q == 1 || q == 5 || q == 6 || q == 10)
        {
            cout << q << endl;
        }
        else if (q == 4)
        {
            int k;
            (w % 2 == 1) ? k = 4 : k = 6;
            cout << k << endl;
        }
        else if (q == 9)
        {
            int k;
            (w == 1) ? k = 9 : (w % 2 == 1) ? k = 2
                                            : k = 8;
            cout << k << endl;
        }
    }
}