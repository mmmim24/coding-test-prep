#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}