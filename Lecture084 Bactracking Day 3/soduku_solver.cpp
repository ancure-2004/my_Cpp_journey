#include <bits/stdc++.h>
bool isSafe(int row, int col, vector<vector<int>> &board, int value)
{

    for (int i = 0; i < 9; i++)
    {

        if (board[row][i] == value)
            return false;

        if (board[i][col] == value)
            return false;

        if (board[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == value)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{

    for (int row = 0; row < 9; row++)
    {

        for (int colm = 0; colm < 9; colm++)
        {

            if (board[row][colm] == 0)
            {

                for (int x = 1; x <= 9; x++)
                {

                    if (isSafe(row, colm, board, x))
                    {

                        board[row][colm] = x;

                        if (solve(board))
                        {

                            return true;
                        }

                        else
                        {

                            board[row][colm] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}