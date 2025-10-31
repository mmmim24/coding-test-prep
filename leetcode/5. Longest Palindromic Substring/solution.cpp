#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int init = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > ans)
                {
                    ans = r - l + 1;
                    init = l;
                }
                l--, r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > ans)
                {
                    ans = r - l + 1;
                    init = l;
                }
                l--, r++;
            }
        }
        return s.substr(init, ans);
    }
};
int main()
{
    string s;
    cin >> s;
    Solution S;
    cout << S.longestPalindrome(s) << endl;
    return 0;
}