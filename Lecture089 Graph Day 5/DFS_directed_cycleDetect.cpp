#include <bits/stdc++.h>

bool CheckCycleDFS(int node, unordered_map<int, bool> &visited,
                   unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{

  visited[node] = true;
  dfsVisited[node] = true;

  for (auto i : adj[node])
  {
    if (!visited[i])
    {
      bool cycleDetect = CheckCycleDFS(i, visited, dfsVisited, adj);
      if (cycleDetect)
        return true;
    }

    else if (dfsVisited[i])
      return true;
  }
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      bool cycleFound = CheckCycleDFS(i, visited, dfsVisited, adj);
      if (cycleFound)
        return true;
    }
  }

  return false;
}