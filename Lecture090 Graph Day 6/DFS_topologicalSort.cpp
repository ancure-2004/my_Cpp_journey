#include <bits/stdc++.h>
void topoSort(int node, unordered_map<int, list<int>> &adj,
              vector<bool> &visited, stack<int> &s)
{

    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
            topoSort(i, adj, visited, s);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSort(i, adj, visited, s);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}