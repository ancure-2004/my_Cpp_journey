class Solution
{
public:
    int solve(int start, int end)
    {
        if (start >= end)
            return 0;

        int maxi = INT_MAX;
        for (int i = start; i <= end; i++)
        {
            maxi = min(maxi, i + max(solve(start, i - 1), solve(i + 1, end)));
        }
        return maxi;
    }

    int getMoneyAmount(int n)
    {
        return solve(1, n);
    }
};