class Solution
{
public:
    int solve(int dice, int faces, int target)
    {
        if (target < 0)
            return 0;

        if (dice == 0 && target != 0)
            return 0;

        if (dice != 0 && target == 0)
            return 0;

        if (dice == 0 && target == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= faces; i++)
        {
            ans = ans + solve(dice - 1, faces, target - i);
        }

        return ans;
    }

    int noOfWays(int m, int n, int x)
    {
        return solve(n, m, x);
    }
};