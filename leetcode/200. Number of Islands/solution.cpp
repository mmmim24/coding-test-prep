#include <bits/stdc++.h>
using namespace std;
class Solution
{

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int row = v.first + directions[i][0];
                int col = v.second + directions[i][1];
                if (
                    row >= 0 && row < grid.size() &&
                    col >= 0 && col < grid[0].size() &&
                    grid[row][col] == '1')
                {
                    q.push({row, col});
                    grid[row][col] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == '1')
                {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    int result = sol.numIslands(grid);
    cout << result << endl;
    return 0;
}