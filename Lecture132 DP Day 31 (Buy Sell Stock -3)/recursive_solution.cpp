class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy, int limits)
    {
        if (index == prices.size())
            return 0;

        if (limits == 0)
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(prices, index + 1, 0, limits);
            int skipKaro = 0 + solve(prices, index + 1, 1, limits);
            profit = max(buyKaro, skipKaro);
        }

        else
        {
            int sellKaro = prices[index] + solve(prices, index + 1, 1, limits - 1);
            int skipKaro = 0 + solve(prices, index + 1, 0, limits);
            profit = max(sellKaro, skipKaro);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {

        return solve(prices, 0, 1, 2);
    }
};