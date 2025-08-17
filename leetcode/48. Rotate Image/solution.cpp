#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> row(n);
        for (int j = 0; j < n; j++)
        {
            cin >> row[j];
        }
        matrix.push_back(row);
    }
    Solution s;
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> row = matrix[i];
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << row[j] << " \n"[j == matrix.size() - 1];
        }
    }
    return 0;
}