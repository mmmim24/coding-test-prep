#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) != mp.end())
            {
                if (mp[pattern[i]] != words[i])
                    return false;
            }
            else
            {
                for (auto it : mp)
                {
                    if (it.second == words[i])
                        return false;
                }
                mp[pattern[i]] = words[i];
            }
        }
        return true;
    }
};
int main()
{
    string pattern = "acca", s = "dog cat dog cat";
    // cin >> pattern >> s;
    Solution S;
    cout << S.wordPattern(pattern, s) << endl;
    return 0;
}