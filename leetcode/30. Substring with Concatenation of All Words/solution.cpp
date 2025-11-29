#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, int> mp;

public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        int wordSize = words[0].size();
        mp.clear();
        for (auto word : words)
            mp[word]++;

        for (int i = 0; i < wordSize; i++)
        {
            int size = 0;
            unordered_map<string, int> seen;
            for (int j = i; j + wordSize <= s.size(); j += wordSize)
            {
                string word = s.substr(j, wordSize);

                auto it = mp.find(word);
                if (it == mp.end())
                {
                    seen.clear();
                    size = 0;
                    continue;
                }

                seen[word]++;
                size++;

                while (seen[word] > it->second)
                {
                    string first = s.substr(j - (size - 1) * wordSize, wordSize);

                    seen[first]--;
                    size--;
                }

                if (size == words.size())
                    ans.push_back(j - (size - 1) * wordSize);
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    string s;
    cin >> s;
    Solution S;
    vector<int> ans = S.findSubstring(s, words);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}