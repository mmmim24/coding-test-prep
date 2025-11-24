#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int sum = nums[0], r = 0, l = 0, ans = INT_MAX;
        while (r < nums.size())
        {
            sum += nums[r++];
            while (sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    Solution s;
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << s.minSubArrayLen(target, nums) << endl;
    return 0;
}