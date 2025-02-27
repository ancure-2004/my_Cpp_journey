class Solution
{
public:
    bool solve(int index, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
            return 0;

        if (index >= n)
            return 0;

        if (target == 0)
            return 1;

        if (dp[index][target] != -1)
            return dp[index][target];

        bool include = solve(index + 1, arr, n, target - arr[index], dp);
        bool exclude = solve(index + 1, arr, n, target, dp);

        dp[index][target] = include or exclude;
        return dp[index][target];
    }

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

        int target = total / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(0, arr, n, target, dp);
    }
};