#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                if (i - mp[nums[i]] > k)
                    mp[nums[i]] = i;
                else
                    return true;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution S;
    cout << S.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}