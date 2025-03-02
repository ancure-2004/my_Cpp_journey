class Solution
{
public:
    int solve(vector<int> &prices, int index, int operation_No, int k)
    {
        if (index == prices.size())
            return 0;

        if (operation_No == 2 * k)
            return 0;

        int profit = 0;
        if (operation_No % 2 == 0)
        {
            int buyKaro = -prices[index] + solve(prices, index + 1, operation_No + 1, k);
            int skipKaro = 0 + solve(prices, index + 1, operation_No, k);
            profit = max(buyKaro, skipKaro);
        }

        else
        {
            int sellKaro = prices[index] + solve(prices, index + 1, operation_No + 1, k);
            int skipKaro = 0 + solve(prices, index + 1, operation_No, k);
            profit = max(sellKaro, skipKaro);
        }

        return profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {

        return solve(prices, 0, 0, k);
    }
};