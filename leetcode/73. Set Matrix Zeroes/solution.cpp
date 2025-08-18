#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        bool zero = false;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i > 0)
                        matrix[i][0] = 0;
                    else
                        zero = true;
                }
            }
        }
        for (int j = 1; j < col; j++)
            if (matrix[0][j] == 0)
            {
                for (int i = 0; i < row; i++)
                    matrix[i][j] = 0;
            }
        for (int i = 1; i < row; i++)
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < col; j++)
                    matrix[i][j] = 0;
            }
        if (matrix[0][0] == 0)
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        if (zero)
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> row(m);
        for (int j = 0; j < m; j++)
        {
            cin >> row[j];
        }
        matrix.push_back(row);
    }
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < n; i++)
    {
        vector<int> row = matrix[i];
        for (int j = 0; j < m; j++)
        {
            cout << row[j] << " \n"[j == m - 1];
        }
    }
    return 0;
}