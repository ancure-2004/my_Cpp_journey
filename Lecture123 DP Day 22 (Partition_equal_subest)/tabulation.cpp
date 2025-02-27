class Solution
{
public:
    bool equalPartition(vector<int> &arr)
    {
        int n = arr.size();

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }

        if (total & 1)
            return 0;

        int t = total / 2;

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= t; target++)
            {

                bool include = 0;
                if (target - arr[index] >= 0)
                    include = dp[index + 1][target - arr[index]];

                bool exclude = dp[index + 1][target];

                dp[index][target] = include or exclude;
            }
        }
        return dp[0][t];
    }
};