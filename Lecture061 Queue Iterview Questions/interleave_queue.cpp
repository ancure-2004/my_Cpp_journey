#include <bits/stdc++.h>
void interLeaveQueue(queue<int> &q)
{

    queue<int> nq;
    int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {

        int element = q.front();
        q.pop();
        nq.push(element);
    }

    while (!nq.empty())
    {

        int element1 = nq.front();
        nq.pop();
        q.push(element1);

        int element2 = q.front();
        q.pop();
        q.push(element2);
    }
}