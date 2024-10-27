#include <bits/stdc++.h>

void solve(stack<int> &inputstack, int count, int N)
{

    // base case
    if (count == N / 2)
    {
        inputstack.pop();
        return;
    }

    int num = inputstack.top();
    inputstack.pop();

    // Recursive Call
    solve(inputstack, count + 1, N);
    inputstack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}