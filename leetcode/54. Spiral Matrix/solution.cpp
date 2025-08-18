#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1, left = 0;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if (left > right || top > bottom)
                break;
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix;
    vector<int> ans;
    for (int i = 0; i < row; i++)
    {
        vector<int> v(col);
        for (int j = 0; j < col; j++)
            cin >> v[j];
        matrix.push_back(v);
    }
    Solution s;
    ans = s.spiralOrder(matrix);
    for (auto el : ans)
        cout << el << " ";
    cout << endl;
    return 0;
}