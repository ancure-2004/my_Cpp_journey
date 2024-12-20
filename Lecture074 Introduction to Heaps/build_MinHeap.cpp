#include <bits/stdc++.h>

void heapify(vector<int> &arr, int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < size && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    return arr;
}