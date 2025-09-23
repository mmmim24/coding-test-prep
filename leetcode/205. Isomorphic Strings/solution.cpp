#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sam;
        for (int i = 0; i < s.size(); i++)
        {
            if (sam.find(s[i]) != sam.end())
            {
                if (sam[s[i]] != t[i])
                    return false;
            }
            else
            {
                for (auto it : sam)
                {
                    if (it.second == t[i])
                        return false;
                }
                sam[s[i]] = t[i];
            }
        }
        return true;
    }
};
int main()
{
    string s, t;
    cin >> s >> t;
    Solution S;
    cout << S.isIsomorphic(s, t) << endl;
    return 0;
}