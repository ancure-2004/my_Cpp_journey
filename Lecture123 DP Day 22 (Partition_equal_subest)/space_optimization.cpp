class Solution
{
public:
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

        int t = total / 2;

        vector<int> curr(t + 1, 0);
        vector<int> next(t + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= t; target++)
            {

                bool include = 0;
                if (target - arr[index] >= 0)
                    include = next[target - arr[index]];

                bool exclude = next[target];

                curr[target] = include or exclude;
            }
            next = curr;
        }
        return next[t];
    }
};