#include <bits/stdc++.h>

int maximumFrequency(vector<int> &arr, int n)
{
    int maxFreq = 0;
    int maxAns = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}