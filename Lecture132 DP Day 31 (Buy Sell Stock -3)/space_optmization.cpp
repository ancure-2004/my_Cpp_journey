class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limits = 1; limits <= 2; limits++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int buyKaro = -prices[index] + next[0][limits];
                        int skipKaro = 0 + next[1][limits];
                        profit = max(buyKaro, skipKaro);
                    }

                    else
                    {
                        int sellKaro = prices[index] + next[1][limits - 1];
                        int skipKaro = 0 + next[0][limits];
                        profit = max(sellKaro, skipKaro);
                    }

                    curr[buy][limits] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};