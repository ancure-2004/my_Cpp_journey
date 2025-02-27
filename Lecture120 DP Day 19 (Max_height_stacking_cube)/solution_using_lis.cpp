class Solution
{
public:
    bool check(vector<int> baseBox, vector<int> nextBox)
    {
        if (baseBox[0] >= nextBox[0] && baseBox[1] >= nextBox[1] && baseBox[2] >= nextBox[2])
            return true;

        else
            return false;
    }

    int solve(int n, vector<vector<int>> &cuboids)
    {

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                    take = cuboids[curr][2] + nextRow[curr + 1];

                int notTake = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {

        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }
};