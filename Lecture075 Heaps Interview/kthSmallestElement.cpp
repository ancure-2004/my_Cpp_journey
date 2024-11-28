//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {

        priority_queue<int> maxHeap;
        for (int i = 0; i <= k - 1; i++)
        {
            maxHeap.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++)
        {
            int root = maxHeap.top();
            if (arr[i] < root)
            {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }

        return maxHeap.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl
             << "~\n";
    }
    return 0;
}

// } Driver Code Ends
