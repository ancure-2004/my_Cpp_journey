class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, int swapped)
    {
        if (index == nums1.size())
            return 0;

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);

        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, 0);

        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));

        return ans;
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        bool swapped = 0;
        return solve(nums1, nums2, 1, swapped);
    }
};