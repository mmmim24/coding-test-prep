#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string foreignDictionary(vector<string> &words)
    {
        return words[0];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    Solution s;
    cout << s.foreignDictionary(words) << endl;
    return 0;
}