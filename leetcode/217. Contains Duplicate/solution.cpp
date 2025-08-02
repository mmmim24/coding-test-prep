#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        set<int> uniqueElements;
        for (int num : nums)
        {
            uniqueElements.insert(num);
        }
        return uniqueElements.size() != nums.size();
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << sol.hasDuplicate(nums) << endl;
    return 0;
}