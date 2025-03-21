class Solution
{
public:
    int solve(int index, int end, vector<int> &slices, int n)
    {
        if (n == 0 || index > end)
            return 0;

        int take = slices[index] + solve(index + 2, end, slices, n - 1);
        int notTake = 0 + solve(index + 1, end, slices, n);

        return max(take, notTake);
    }

    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        int case1 = solve(0, k - 2, slices, k / 3);
        int case2 = solve(1, k - 1, slices, k / 3);

        return max(case1, case2);
    }
};