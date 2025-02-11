#include <bits/stdc++.h>
int solve(int n)
{

    if (n == 0)
        return 0;

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i));
    }
    return ans;
}

int MinSquares(int n)
{
    return solve(n);
}