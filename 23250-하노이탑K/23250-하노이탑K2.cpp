#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl "\n"
typedef unsigned long long int ulli;

/*
원판 넘버(k) -> 2진수를 원판 넘버

몇번 반복했는지(원판 넘버) -> int 이동 횟수
출력함수(원판갯수,원판번호,이동횟수)  -> start -> dest

*/
ulli disk_num(ulli q) //해당 k시 이동하는 원판 번호
{
    ulli count = 0;
    while (q % 2 == 0) // 처음으로 1 나오는 이진수 자릿수 찾기
    {
        count++;
        q = q >> 1;
    }
    // count=2  100 ,  3번 원판
    return count + 1;
}

ulli move_count(ulli q, ulli diskNum)
{
    // 100 -> 3
    // 110100 -> 52,   110(6) +1 =7번 째
    return ulli((q >> diskNum) + 1);
}

void solution(const ulli n, const ulli diskNum, const ulli move)
{
    ulli divid_n = n % 2;
    ulli divid_disk = diskNum % 2;
    if (divid_n == divid_disk) //짝수 짝수, 홀수 홀수
    {
        // A->C->B->A
        switch (move % 3)
        {
        case 0: // 3번째 이동 (2->1) (B->A)
            cout << "2 1" << endl;
            break;
        case 1: // 1번째 이동 (A->C)
            cout << "1 3" << endl;
            break;
        case 2: // 2번째 C->B
            cout << "3 2" << endl;
            break;
        }
    }
    else
    {
        // A->B->C->A
        switch (move % 3)
        {
        case 0: // 3번째 이동 (2->1) (C->A)
            cout << "3 1" << endl;
            break;
        case 1: // 1번째 이동
            cout << "1 2" << endl;
            break;
        case 2: // 2번째 이동
            cout << "2 3" << endl;
            break;
        }
    }
}

int main()
{
    int n;
    ulli k;
    cin >> n >> k;
    ulli diskNum = disk_num(k);
    ulli moveCount = move_count(k, diskNum);
    solution(n, diskNum, moveCount);
}
/**/