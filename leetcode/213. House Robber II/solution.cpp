#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = 0, curr = 0, rob1 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = max(nums[i] + prev, curr);
            prev = curr;
            curr = temp;
        }
        rob1 = curr, prev = 0, curr = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int temp = max(nums[i] + prev, curr);
            prev = curr;
            curr = temp;
        }
        return max(nums[0], max(curr, rob1));
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << Solution().rob(v) << endl;
    return 0;
}
