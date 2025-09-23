#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> sam, tam;
        for (int i = 0; i < s.size(); i++)
        {
            if (sam.find(s[i]) != sam.end())
            {
                if (i != sam[s[i]])
                    return false;
            }
            else
            {
                sam[s[i]] = i;
            }
            if (tam.find(t[i]) != tam.end())
            {
                if (i != tam[t[i]])
                    return false;
            }
            else
            {
                tam[t[i]] = i;
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