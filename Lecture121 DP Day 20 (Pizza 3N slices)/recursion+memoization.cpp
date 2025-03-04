class Solution
{
public:
    int solve(int index, int end, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || index > end)
            return 0;

        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solve(index + 2, end, slices, n - 1, dp);
        int notTake = 0 + solve(index + 1, end, slices, n, dp);

        return dp[index][n] = max(take, notTake);
    }

    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int case1 = solve(0, k - 2, slices, k / 3, dp1);
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solve(1, k - 1, slices, k / 3, dp2);
        return max(case1, case2);
    }
};