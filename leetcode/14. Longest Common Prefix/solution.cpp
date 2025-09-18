#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size() - 1], res = "";
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return res;
            }
            res += first[i];
        }
        return res;
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
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}