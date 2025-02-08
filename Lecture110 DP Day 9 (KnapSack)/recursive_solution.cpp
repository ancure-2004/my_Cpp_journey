#include <bits/stdc++.h>
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{

    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];

        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, capacity);
    int ans = max(include, exclude);
    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n - 1, maxWeight);
}