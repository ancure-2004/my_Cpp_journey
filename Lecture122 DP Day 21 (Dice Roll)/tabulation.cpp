int noOfWays(int m, int n, int x)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] == 1;

    for (int dice = 1; dice <= n; dice++)
    {
        for (int target = 1; target <= x; target++)
        {

            int ans = 0;
            for (int face = 1; face <= m; face++)
            {
                if (target - face >= 0)
                    ans = ans + dp[dice - 1][target - face];
            }

            dp[dice][target] = ans;
        }
    }
    return dp[n][x];
}