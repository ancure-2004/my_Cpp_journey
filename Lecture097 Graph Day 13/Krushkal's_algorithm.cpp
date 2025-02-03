#include <bits/stdc++.h>
#include <algorithm>

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void make_set(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_parent(vector<int> &parent, int node)
{

    if (parent[node] == node)
        return node;

    return parent[node] = find_parent(parent, parent[node]);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{

    u = find_parent(parent, u);
    v = find_parent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    make_set(parent, rank, n);

    int minweight = 0;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = find_parent(parent, edges[i][0]);
        int v = find_parent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {
            minweight += wt;
            union_set(u, v, parent, rank);
        }
    }
    return minweight;
}