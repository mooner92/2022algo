#include <iostream>
using namespace std;
int k[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >>tc;

    for(int i=0;i<tc;i++){
        int a;
        cin>>a;
        k[a]++;
    }

    for(int i = 1 ; i <= 10000; i++)
        for (int j = 0; j < k[i]; j++)
            cout << i << "\n";
}