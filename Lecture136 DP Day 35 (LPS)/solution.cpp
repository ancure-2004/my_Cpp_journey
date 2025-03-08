class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());

        vector<int> curr(revStr.length() + 1);
        vector<int> next(revStr.length() + 1);

        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = revStr.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (s[i] == revStr[j])
                    ans = 1 + next[j + 1];

                else
                {
                    ans = max(curr[j + 1], next[j]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};