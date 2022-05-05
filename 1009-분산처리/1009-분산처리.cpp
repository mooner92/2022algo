#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {

        int a = 0, b = 0;
        cin >> a >> b;
        switch (a)
        {
        case 1:
            cout << a;
            break;
        case 2:
            switch (b % 4)
            {
            case 1:
                cout << 2;
                break;
            case 2:
                cout << 4;
                break;
            case 3:
                cout << 8;
                break;
            case 0:
                cout << 6;
                break;
            default:
                break;
            }
        case 3:
            switch (b % 4)
            {
            case 1:
                cout << 3;
                break;
            case 2:
                cout << 9;
                break;
            case 3:
                cout << 7;
                break;
            case 0:
                cout << 1;
                break;
            default:
                break;
            }
        case 4:
            switch (b % 2)
            {
            case 1:
                cout << 4;
                break;
            case 0:
                cout << 6;
                break;
            default:
                break;
            }
        case 5:
            cout << a;
            break;
        case 6:
            cout << a;
            break;
        case 7:
            switch (b % 4)
            {
            case 1:
                cout << 7;
                break;
            case 2:
                cout << 9;
                break;
            case 3:
                cout << 3;
                break;
            case 0:
                cout << 1;
                break;
            default:
                break;
            }
        case 8:
            switch (b % 4)
            {
            case 1:
                cout << 8;
                break;
            case 2:
                cout << 4;
                break;
            case 3:
                cout << 2;
                break;
            case 0:
                cout << 6;
                break;
            default:
                break;
            }
        case 9:
            (b == 1) ? cout << 9 : (b % 2 == 0) ? cout << 8
                                                : cout << 2;
            break;
        case 10:
            cout << 10;
            break;
        default:
            break;
        }
    }
}