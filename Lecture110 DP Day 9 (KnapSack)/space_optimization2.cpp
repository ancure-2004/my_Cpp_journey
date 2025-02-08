#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> curr(maxWeight + 1, 0);

    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w - weight[index]];
            }
            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
        }
    }

    return curr[maxWeight];
}