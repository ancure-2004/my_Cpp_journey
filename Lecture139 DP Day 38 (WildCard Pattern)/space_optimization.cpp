class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<int> curr(p.length() + 1, 0);
        vector<int> prev(p.length() + 1, 0);

        prev[0] = true;

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
            prev[j] = flag;
        }

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= p.length(); j++)
            {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }

                else if (p[j - 1] == '*')
                {
                    curr[j] = (curr[j - 1] || prev[j]);
                }

                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[p.length()];
    }
};