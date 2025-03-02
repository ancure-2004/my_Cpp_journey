class Solution
{
public:
    int solve(vector<int> &prices, int index, int operation_No, int k, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (operation_No == 2 * k)
            return 0;

        if (dp[index][operation_No] != -1)
            return dp[index][operation_No];

        int profit = 0;
        if (operation_No % 2 == 0)
        {
            int buyKaro = -prices[index] + solve(prices, index + 1, operation_No + 1, k, dp);
            int skipKaro = 0 + solve(prices, index + 1, operation_No, k, dp);
            profit = max(buyKaro, skipKaro);
        }

        else
        {
            int sellKaro = prices[index] + solve(prices, index + 1, operation_No + 1, k, dp);
            int skipKaro = 0 + solve(prices, index + 1, operation_No, k, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][operation_No] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(prices, 0, 0, k, dp);
    }
};