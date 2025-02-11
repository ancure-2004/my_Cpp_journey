#include <bits/stdc++.h>

int maxSquare(vector<vector<int>> &mat)
{
    int maxi = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(dp[i][j], maxi);
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxi;
}