class Solution
{
public:
    int solve(vector<int> &prices, int index, int buy)
    {
        if (index == prices.size())
            return 0;

        int profit = 0;
        if (buy)
        {
            int buyKaro = -prices[index] + solve(prices, index + 1, 0);
            int skipKaro = 0 + solve(prices, index + 1, 1);
            profit = max(buyKaro, skipKaro);
        }

        else
        {
            int sellKaro = prices[index] + solve(prices, index + 1, 1);
            int skipKaro = 0 + solve(prices, index + 1, 0);
            profit = max(sellKaro, skipKaro);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {

        return solve(prices, 0, 1);
    }
};