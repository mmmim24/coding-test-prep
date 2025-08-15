#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> res;
        vector<vector<string>> ans;
        for (auto i : strs)
        {
            string sorted = i;
            sort(sorted.begin(), sorted.end());
            res[sorted].push_back(i);
        }
        for (auto i : res)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " \n"[j == res[i].size() - 1];
    return 0;
}
