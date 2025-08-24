#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> result;
        backtrack(nums, target, result, 0);
        return results;
    }

    void backtrack(vector<int> &nums, int target, vector<int> &result, int i)
    {
        if (target == 0)
        {
            results.push_back(result);
            return;
        }
        if (target < 0)
        {
            return;
        }
        if (i >= nums.size())
        {
            return;
        }
        result.push_back(nums[i]);
        backtrack(nums, target - nums[i], result, i);
        result.pop_back();
        backtrack(nums, target, result, i + 1);
    }
};
int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> target;
    Solution s;
    vector<vector<int>> ans = s.combinationSum(nums, target);
    for (auto row : ans)
    {
        for (int i = 0; i < row.size(); i++)
        {
            cout << row[i] << " \n"[i == row.size() - 1];
        }
    }
    return 0;
}