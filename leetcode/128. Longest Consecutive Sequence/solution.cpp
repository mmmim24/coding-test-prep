#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        int res = INT_MIN, cnt;
        nums.size() > 0 ? cnt = 1 : cnt = 0;
        vector<int> vrr(st.begin(), st.end());
        for (int i = 0; i < vrr.size(); i++)
        {
            if (vrr[i] - vrr[i - 1] == 1)
                cnt++;
            else
            {
                res = max(res, cnt);
                cnt = 1;
            }
        }
        return max(res, cnt);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), vec = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution s;
    cout << s.longestConsecutive(vec) << "\n";
    return 0;
}
