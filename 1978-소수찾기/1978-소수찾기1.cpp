#include <iostream>
using namespace std;

int main()
{
    int nums;
    cin >> nums;
    int *arr;
    arr = new int[nums];

    for (int i = 0; i < nums; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    for (int i = 0; i < nums; i++)
    {
        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
                break;
            if (arr[i] == j)
                cout << arr[i] << '\n';
        }
    }

    delete[] arr;
    return 0;
}