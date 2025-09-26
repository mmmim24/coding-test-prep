#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans = {};
        if (nums.size() < 1)
            return ans;
        vector<int> temp;
        int prev = nums[0];
        temp.push_back(prev);
        for (int i = 1; i < nums.size(); i++)
        {
            if ((long long)nums[i] - (long long)prev != 1ll)
            {
                string s = to_string(temp[0]);
                if (temp.size() > 1)
                    s += "->" + to_string(temp[temp.size() - 1]);
                ans.push_back(s);
                temp.clear();
            }
            prev = nums[i];
            temp.push_back(prev);
        }
        if (!temp.empty())
        {
            string s = to_string(temp[0]);
            if (temp.size() > 1)
                s += "->" + to_string(temp[temp.size() - 1]);
            ans.push_back(s);
            temp.clear();
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
    vector<string> ans = S.summaryRanges(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " \n";
    }
    return 0;
}