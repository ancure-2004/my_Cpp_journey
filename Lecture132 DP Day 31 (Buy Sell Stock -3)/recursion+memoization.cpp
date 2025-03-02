class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy, int limits, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (limits == 0)
            return 0;

        if (dp[index][buy][limits] != -1)
            return dp[index][buy][limits];

        int profit = 0;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(prices, index + 1, 0, limits, dp);
            int skipKaro = 0 + solve(prices, index + 1, 1, limits, dp);
            profit = max(buyKaro, skipKaro);
        }

        else
        {
            int sellKaro = prices[index] + solve(prices, index + 1, 1, limits - 1, dp);
            int skipKaro = 0 + solve(prices, index + 1, 0, limits, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[index][buy][limits] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2, dp);
    }
};