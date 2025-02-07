#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}