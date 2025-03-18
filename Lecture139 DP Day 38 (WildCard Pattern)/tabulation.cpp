class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));

        dp[0][0] = true;

        for (int j = 1; j <= p.length(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= p.length(); j++)
            {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (p[j - 1] == '*')
                {
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
                }

                else
                    dp[i][j] = false;
            }
        }
        return dp[s.length()][p.length()];
    }
};