#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0, dest = 0, maxDest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxDest = max(maxDest, i + nums[i]);
            if (i == dest)
            {
                ans++;
                dest = maxDest;
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution S;
    cout << S.jump(nums) << "\n";
    return 0;
}