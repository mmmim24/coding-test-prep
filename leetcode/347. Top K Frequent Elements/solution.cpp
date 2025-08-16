#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto m : mp)
        {
            heap.push({m.second, m.first});
            if (heap.size() > k)
                heap.pop();
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    Solution s;
    vector<int> res = s.topKFrequent(nums, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " \n"[i == res.size() - 1];
    return 0;
}
