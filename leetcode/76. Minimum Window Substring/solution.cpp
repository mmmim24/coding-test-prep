#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> window, need;
        for (char c : t)
            need[c]++;
        int n = s.size(), i = 0, l = 0, r = 0, sz = 0, len = INT_MAX;
        while (r < n)
        {
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                sz++;

            while (need.size() == sz)
            {
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    i = l;
                }

                char x = s[l];
                window[x]--;

                if (need.count(x) && window[x] < need[x])
                    sz--;
                l++;
            }
            r++;
        }
        return len == INT_MAX ? "" : s.substr(i, len);
    }
};
int main()
{
    string s, t;
    cin >> s >> t;
    Solution S;
    cout << S.minWindow(s, t) << endl;
    return 0;
}