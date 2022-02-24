#include <iostream>  //사칙연산 법칙은 적용하지 않는 문제임
#include <string>
using namespace std;

int main() {

    double n, t; //t는 integer로 받아도 상관 x
    string x;
    cin >> t;

    while (t--)
    {

        cin >> n;
        getline(cin, x);
        for(int i = 0; i < x.size(); i++)
            switch (x[i])  //문자열을 매 칸으로 나누어 case로 걸러냄
            {              //@,#,%을 제외한 다른 문자는 바로 건너뜀 
            case '@':
                n *= 3;
                break;
            case '#':
                n -= 7;
                break;
            case '%':
                n += 5;
                break;
            }
        printf("%.2f\n", n); //소수점 둘째자리까지 출력 
    }
    
}