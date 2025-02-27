class Solution
{
public:
    int solve(int index, int diff, vector<int> &arr)
    {
        if (index < 0)
            return 0;

        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (arr[index] - arr[j] == diff)
                ans = max(ans, 1 + solve(j, diff, arr));
        }
        return ans;
    }

    int lengthOfLongestAP(vector<int> &arr)
    {

        int n = arr.size();
        if (n <= 2)
            return n;

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                ans = max(ans, 2 + solve(i, arr[j] - arr[i], arr));
            }
        }
        return ans;
    }
};