#include <bits/stdc++.h>

void dfs(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list<int>> &adjList, vector<int> &component)
{

    component.push_back(node);
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < V; i++)
    {
        vector<int> component;
        if (!visited[i])
        {
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}