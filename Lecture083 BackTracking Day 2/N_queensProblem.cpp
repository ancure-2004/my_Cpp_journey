
#include <bits/stdc++.h>

void addSolution(vector<vector<int>> &boards, vector<vector<int>> &ans, int n)
{

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(boards[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &boards, int n)
{

    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (boards[x][y] == 1)
            return false;

        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (boards[x][y] == 1)
            return false;

        x--;
        y--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (boards[x][y] == 1)
            return false;

        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &boards, int n)
{

    if (col == n)
    {
        addSolution(boards, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, boards, n))
        {

            boards[row][col] = 1;
            solve(col + 1, ans, boards, n);
            boards[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> boards(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, boards, n);

    return ans;
}