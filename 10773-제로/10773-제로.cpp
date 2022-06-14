#include <iostream>
using namespace std;
using ll = long long;

struct stack
{
    int arr[1000000];
    int l;

    void init()
    {
        l = -1; // l을 -1로 지정
    }
    void push(int d)
    {
        arr[++l] = d;
    }
    bool empty()
    {
        return (l < 0); // init을 해 주는 이유 bool값을 음수와 양수로 나눠서 계산해주기 위함
    }
    int pop()
    {
        if (empty())
        {
            return -1;
        }
        return arr[l--];
    }
    int size()
    {
        return l + 1;
    }
    int top()
    {
        if (empty())
        {
            return -1;
        }
        return arr[l];
    }
};

int main()
{
    int tc;
    cin >> tc;
    stack s;
    for (int i = 0; i < tc; i++)
    {
        int q;
        cin >> q;
        if (q != 0)
        { //받은 수 q가 0이 아닐때
            s.push(q);
        }
        else //받은 수 q가 0일 때
            s.pop();
    }                  // for문의 끝에서 스택을 완성
    bool exit = false; // bool exit으로 탈줄 시퀀스
    ll sum = 0;        // sum을 0으로 설정
    while (exit == false)
    {
        if (s.empty() == 1)
        { // s가 비었으면 탈출
            exit = true;
        }
        else
        {
            sum += s.top();
            s.pop();
        }
    }
    cout << sum;
} //자리수 초과