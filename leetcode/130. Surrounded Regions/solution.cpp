#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j, int row, int col)
    {
        if (i < 0 or j < 0 or i >= row or j >= col or board[i][j] != 'O')
            return;
        board[i][j] = '#';
        DFS(board, i - 1, j, row, col);
        DFS(board, i + 1, j, row, col);
        DFS(board, i, j - 1, row, col);
        DFS(board, i, j + 1, row, col);
    }

    void solve(vector<vector<char>> &board)
    {

        int row = board.size();

        if (row == 0)
            return;

        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
                DFS(board, i, 0, row, col);
            if (board[i][col - 1] == 'O')
                DFS(board, i, col - 1, row, col);
        }

        for (int j = 0; j < col; j++)
        {
            if (board[0][j] == 'O')
                DFS(board, 0, j, row, col);
            if (board[row - 1][j] == 'O')
                DFS(board, row - 1, j, row, col);
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};

int main()
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    Solution s;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " \n"[j == board[0].size() - 1];
        }
    }

    s.solve(board);
    cout << "\n\n";

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " \n"[j == board[0].size() - 1];
        }
    }

    return 0;
}