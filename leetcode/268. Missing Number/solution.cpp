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
class SolutionXOR
{
public:
    int missingNumber(vector<int> &nums)
    {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= (i ^ nums[i]);
        }
        return result;
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
    // Solution s;
    SolutionXOR s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}