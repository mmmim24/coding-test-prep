#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;
        int cnt = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            if (cnt <= 1)
            {
                nums[k++] = nums[i];
                prev = nums[i];
            }
        }
        return k;
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
    cout << S.removeDuplicates(nums) << endl;
    return 0;
}