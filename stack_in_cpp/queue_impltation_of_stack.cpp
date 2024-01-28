#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1,s2;

    void enQueue(int x)
    {
        while(s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int deQueue()
    {
        if(s1.empty())
        {
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n' ;
    cout << q.deQueue() << '\n' ;
    cout << q.deQueue() << '\n' ;

    return 0;
}