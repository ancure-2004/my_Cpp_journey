

class Solution
{
public:
    int solve(int n, vector<int> &arr, int curr, int prev)
    {
        if (curr == n)
            return 0;

        int take = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            take = 1 + solve(n, arr, curr + 1, curr);

        int notTake = 0 + solve(n, arr, curr + 1, prev);

        return max(take, notTake);
    }

    int lis(vector<int> &arr)
    {

        int n = arr.size();
        return solve(n, arr, 0, -1);
    }
};