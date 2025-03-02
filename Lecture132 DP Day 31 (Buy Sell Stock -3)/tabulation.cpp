class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limits = 1; limits <= 2; limits++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int buyKaro = -prices[index] + dp[index + 1][0][limits];
                        int skipKaro = 0 + dp[index + 1][1][limits];
                        profit = max(buyKaro, skipKaro);
                    }

                    else
                    {
                        int sellKaro = prices[index] + dp[index + 1][1][limits - 1];
                        int skipKaro = 0 + dp[index + 1][0][limits];
                        profit = max(sellKaro, skipKaro);
                    }

                    dp[index][buy][limits] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};