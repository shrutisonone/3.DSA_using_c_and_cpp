#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> stk;
    stk.push(20);
    stk.push(21);
    stk.push(22);
    stk.push(23);
    stk.push(24);

    int num = 0;

    stk.push(num);
    stk.pop();
    stk.pop();
    stk.pop();

    while(!stk.empty())
    {
        cout << stk.top() <<" ";
        stk.pop();
    }
}