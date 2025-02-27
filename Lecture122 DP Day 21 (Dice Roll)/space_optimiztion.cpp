class Solution
{
public:
    int noOfWays(int m, int n, int x)
    {
        vector<int> prev(x + 1, 0);
        vector<int> curr(x + 1, 0);
        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++)
        {
            for (int target = 1; target <= x; target++)
            {

                int ans = 0;
                for (int face = 1; face <= m; face++)
                {
                    if (target - face >= 0)
                        ans = ans + prev[target - face];
                }

                curr[target] = ans;
            }
            prev = curr;
        }
        return curr[x];
    }
};