#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m, r;
        for (auto i : ransomNote)
            r[i]++;
        for (auto i : magazine)
            m[i]++;
        for (auto i : ransomNote)
        {
            if (r[i] > m[i])
                return false;
        }
        return true;
    }
};
int main()
{
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    Solution s;
    cout << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}