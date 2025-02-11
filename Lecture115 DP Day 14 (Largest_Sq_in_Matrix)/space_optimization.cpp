#include <bits/stdc++.h>

int maxSquare(vector<vector<int>> &mat)
{
    int maxi = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(curr[j], maxi);
            }
            else
                curr[j] = 0;
        }
        next = curr;
    }
    return maxi;
}