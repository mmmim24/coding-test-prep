#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<int, int> cnt;
        int res = 0, l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++)
        {
            cnt[s[r]]++;
            maxf = max(maxf, cnt[s[r]]);
            if (r - l + 1 - maxf > k)
            {
                cnt[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
int main()
{
    string s;
    int k;
    cin >> s >> k;
    Solution sol;
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}