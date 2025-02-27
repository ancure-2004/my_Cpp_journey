class Solution
{
public:
    bool solve(int index, vector<int> &arr, int n, int target)
    {
        if (target < 0)
            return 0;

        if (index >= n)
            return 0;

        if (target == 0)
            return 1;

        bool include = solve(index + 1, arr, n, target - arr[index]);
        bool exclude = solve(index + 1, arr, n, target);

        return include or exclude;
    }

    bool equalPartition(vector<int> &arr)
    {
        int n = arr.size();

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }

        if (total & 1)
            return 0;

        int target = total / 2;

        return solve(0, arr, n, target);
    }
};