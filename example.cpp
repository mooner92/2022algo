/*#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string x;
    getline(cin,x);
    cout << x.size() <<"\n";
    cout << x.length();     //같은 값이 나온다...
    double a=10.3;
    cout << a/4.0;

double a=63.99;
cout << sqrt(a) << endl;
int k =a;
int c = sqrt(a);
cout << k <<"\n" <<c;
int a;
cin>>a;
cout << a*2;
}
*/

/*#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int tmp, n;

    // a에 큰 값 배치를 위한 반복문
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    //유클리드 알고리즘 부분
    // a%b진행(b가 0이 될때까지)
    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int x, y, r1, r2;
    cin >> x >> y;
    r1 = gcd(x, y);
    r2 = lcm(x, y);
    cout << r1 << endl
         << r2;
}
*/

/*#include <stdio.h>

int main()
{
    int n,m;
    int cl[] = {500, 100, 50, 10};
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; n != 0; i++)
    {
        int pivot = n / cl[i];
        cnt += pivot;
        printf("%d원 동전의 개수 = %d\n", cl[i], pivot);
        n %= cl[i];
    }
    printf("총 동전의 개수 = %d", cnt);
}
