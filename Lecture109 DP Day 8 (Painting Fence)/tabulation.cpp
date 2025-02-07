#include <bits/stdc++.h>
#define MOD 1000000007
int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int numberOfWays(int n, int k)
{

    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int same = mul(dp[i - 2], k - 1);
        int diff = mul(dp[i - 1], k - 1);
        dp[i] = add(same, diff);
    }

    return dp[n];
}
