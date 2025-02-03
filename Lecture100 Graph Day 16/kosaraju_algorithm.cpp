#include <bits/stdc++.h>

void revDFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{

    vis[node] = true;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDFS(nbr, adj, vis);
        }
    }
}

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, st, adj);
        }
    }

    st.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int v = edges[i][0];
        int u = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    int count = 0;
    while (!st.empty())
    {

        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            count++;
            revDFS(top, transpose, vis);
        }
    }

    return count;
}