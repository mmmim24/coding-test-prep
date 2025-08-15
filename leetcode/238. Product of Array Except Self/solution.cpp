#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        // create the suffix product array first
        for (int i = n - 2; i > -1; i--)
        {
            res[i] = res[i + 1] * nums[i + 1];
        }
        // now instead of creating an extra array
        // and create the resultant array multiplying
        // the suffix and prefix arrays, multiply
        // nums[0] * res[1]. Then nums[0] * nums[1] * res[2]
        // and so on. so create a variable for O(1) space
        // to store the multiplication from nums[0] to nums[n-1]
        int multiplier = nums[0];
        for (int i = 1; i < n; i++)
        {
            res[i] *= multiplier;
            multiplier *= nums[i];
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution s;
    vector<int> ans = s.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}