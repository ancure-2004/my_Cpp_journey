#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(nodes);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}