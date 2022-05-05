#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int q, w;
        cin >> q >> w;
        q %= 10;
        // cout << q << endl;
        if (q == 2 || q == 3 || q == 7 || q == 8)
        {
            int t = w % 4;
            if (t == 1)
                cout << q << "\n";
            else if (t == 2)
            {
                if (q == 2 || q == 8)
                    cout << 4 << "\n";
                else if (q == 3 || q == 7)
                    cout << 9 << "\n";
            }
            else if (t == 3)
            {
                int k;
                (q == 2) ? k = 8 : (q == 3) ? k = 7
                               : (q == 7)   ? k = 3
                               : (q == 8)   ? k = 2
                                            : k = 2;
                cout << k << "\n";
            }
            else if (t == 0)
            {
                int j;
                (q == 2 || 1 == 8) ? j = 6 : (q == 3 || q == 7) ? j = 1
                                                                : j = 1;
                cout << j << "\n";
            }
        }
        else if (q == 1 || q == 5 || q == 6)
        {
            cout << q << "\n";
        }
        else if (q == 4 || q == 9)
        {
            int t = w % 2;
            if (t == 1)
            {
                if (q == 4)
                    cout << 4 << "\n";
                else if (q == 9)
                    cout << 9 << "\n";
            }
            else if (t == 0)
            {
                if (q == 4)
                    cout << 6 << "\n";
                else if (q == 9)
                    cout << 1 << "\n";
            }
        }

        else if (q == 0)
            cout << 10 << "\n";
        }
}

/*
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
                                            : false;
                cout << k << endl;
                break;
            case 0:
                int j;
                (q == 2 || 1 == 8) ? j = 6 : (q == 3 || q == 7) ? j = 1
                                                                : false;
                cout << j << endl;
                break;
            default:
                cout << "none";
            }
*/