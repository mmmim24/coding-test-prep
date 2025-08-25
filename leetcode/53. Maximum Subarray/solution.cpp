#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxS = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (maxS < 0)
                maxS = 0;
            maxS += nums[i];
            res = max(maxS, res);
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
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}