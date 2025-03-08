class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        if (i == a.length())
            return 0;

        if (j == b.length())
            return 0;

        int ans = 0;
        if (a[i] == b[j])
            ans = 1 + solve(a, b, i + 1, j + 1);

        else
        {
            ans = max(solve(a, b, i, j + 1), solve(a, b, i + 1, j));
        }
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return solve(text1, text2, 0, 0);
    }
};