#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (const string &s : strs)
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, length));
            j = j + 1 + length;
            i = j;
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    Solution s;
    string str = s.encode(strs);
    cout << str << endl;
    ans = s.decode(str);
    for (int i = 0; i < n; i++)
    {
        cout << strs[i] << " \n"[i == n - 1];
    }
    return 0;
}
