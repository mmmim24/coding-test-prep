#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> LIS(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                    LIS[j] = max(LIS[j], LIS[i] + 1);
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << Solution().lengthOfLIS(nums) << endl;
    return 0;
}