#include <bits/stdc++.h>
using namespace std;
class SolutionMinEl
{
public:
    int findMin(vector<int> &nums)
    {
        auto res = min_element(nums.begin(), nums.end());
        return *res;
    }
};
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return nums[l];
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
    cout << s.findMin(nums) << endl;
    return 0;
}