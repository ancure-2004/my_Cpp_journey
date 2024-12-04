#include <bits/stdc++.h>

class node
{
public:
    int data;
    int row;
    int column;

    node(int d, int i, int j)
    {
        data = d;
        row = i;
        column = j;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{

    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> min_heap;

    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        min_heap.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    while (!min_heap.empty())
    {
        node *temp = min_heap.top();
        min_heap.pop();
        mini = temp->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (temp->column + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->column + 1]);
            min_heap.push(new node(a[temp->row][temp->column + 1], temp->row, temp->column + 1));
        }

        else
            break;
    }

    return (end - start + 1);
}