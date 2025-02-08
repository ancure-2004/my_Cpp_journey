#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + prev[w - weight[index]];
            }
            int exclude = 0 + prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[maxWeight];
}