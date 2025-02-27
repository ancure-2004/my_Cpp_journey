class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();
        int nextSwap = 0;
        int nextNoSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {

                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = nextNoSwap;

                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + nextSwap);

                if (swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            nextSwap = currSwap;
            nextNoSwap = currNoSwap;
        }
        return min(currSwap, currNoSwap);
    }
};