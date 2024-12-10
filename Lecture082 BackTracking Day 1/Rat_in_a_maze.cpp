#include <bits/stdc++.h>

bool isSafe(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{

    if ((i >= 0 && i < n) && (j >= 0 && j < n) && arr[i][j] == 1 && visited[i][j] != 1)
    {

        return true;
    }

    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, vector<string> &ans, int n,
           vector<vector<bool>> &visited, string path)
{

    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // DOWN
    if (isSafe(x + 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x + 1, y, arr, ans, n, visited, path + 'D');
        visited[x][y] = 0;
    }

    // LEFT
    if (isSafe(x, y - 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y - 1, arr, ans, n, visited, path + 'L');
        visited[x][y] = 0;
    }

    // RIGHT
    if (isSafe(x, y + 1, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x, y + 1, arr, ans, n, visited, path + 'R');
        visited[x][y] = 0;
    }

    // UP
    if (isSafe(x - 1, y, visited, arr, n))
    {
        visited[x][y] = 1;
        solve(x - 1, y, arr, ans, n, visited, path + 'U');
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, ans, n, visited, path);
    return ans;
}