class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        sort(satisfaction.begin(), satisfaction.end());

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};