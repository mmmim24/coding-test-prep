#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int j = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (st.find(s[i]) != st.end())
            {
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}