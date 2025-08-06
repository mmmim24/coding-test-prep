#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int diff;
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            if (mp.count(diff) && mp[diff] != i)
            {
                return {i, mp[diff]};
            }
        }
        return {};
    }
};

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " \n"[i == 1];
    }
    return 0;
}