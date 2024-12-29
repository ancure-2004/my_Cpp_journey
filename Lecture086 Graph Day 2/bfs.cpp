#include <bits/stdc++.h>

void bfs(int node, unordered_map<int, bool> &visited, vector<vector<int>> &adj, vector<int> &ans)
{

    queue<int> q;

    q.push(node);

    visited[node] = true;

    while (!q.empty())
    {

        int frontNode = q.front();

        q.pop();

        ans.push_back(frontNode);

        for (auto i : adj[frontNode])
        {

            if (!visited[i])
            {

                q.push(i);

                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{

    vector<int> ans;

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[0])
            bfs(0, visited, adj, ans);
    }
    return ans;
}