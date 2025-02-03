#include <bits/stdc++.h>

void dfs(int node, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis,
         int parent, unordered_map<int, list<int>> &adj, vector<vector<int>> &result,
         int &timer)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            dfs(nbr, disc, low, vis, node, adj, result, timer);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }

        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, disc, low, vis, parent, adj, result, timer);
    }

    return result;
}