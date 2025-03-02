class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int operation_No = 0; operation_No < 2 * k; operation_No++)
            {
                int profit = 0;
                if (operation_No % 2 == 0)
                {
                    int buyKaro = -prices[index] + next[operation_No + 1];
                    int skipKaro = 0 + next[operation_No];
                    profit = max(buyKaro, skipKaro);
                }

                else
                {
                    int sellKaro = prices[index] + next[operation_No + 1];
                    int skipKaro = 0 + next[operation_No];
                    profit = max(sellKaro, skipKaro);
                }

                curr[operation_No] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};