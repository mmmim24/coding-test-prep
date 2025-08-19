#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] == target)
            {
                return m;
            }

            if (nums[l] > nums[m])
            {
                if (target > nums[m] && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            else
            {
                if (target <= nums[m] && target >= nums[l])
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return -1;
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
    cout << s.search(nums, target) << endl;
    return 0;
}