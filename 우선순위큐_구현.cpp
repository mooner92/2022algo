#include <iostream>
#include <vector>
using namespace std;

template <class T, class CONT = std::vector<T>, class CMP = less<typename CONT::value_type>>
class mypriority_queue
{
private:
    CONT container;
    int num;
    CMP compare;

public:
    mypriority_queue()
    {
        num = 0;
        container.push_back(0);
    }

    bool empty()
    {
        if (num)
            return false;
        else
            return true;
    }

    int size()
    {
        return num;
    }

    T top()
    {
        return container[1];
    }

    void push(T input)
    {
        num++;
        container.push_back(input);
        int now = num;
        while (now > 1)
        {
            if (compare(container[now / 2], input))
            {
                container[now] = container[now / 2];
                now /= 2;
            }
            else
            {
                break;
            }
        }
        container[now] = input;
    }

    void pop()
    {
        if (!num)
            return;
        int pivot = container[num];
        container.pop_back();
        num--;
        int now = 2;
        while (now <= num)
        {
            if (now + 1 <= num)
            {
                if (compare(container[now], container[now + 1]))
                {
                    now++;
                }
            }
            if (compare(pivot, container[now]))
            {
                container[now / 2] = container[now];
                now *= 2;
            }
            else
            {
                break;
            }
        }
        container[now / 2] = pivot;
    }
};
//