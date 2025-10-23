#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> cnt(n + 1, 0);
        for (auto el : citations)
        {
            if (el >= n)
                cnt[n]++;
            else
                cnt[el]++;
        }
        int ans = 0;
        for (int i = n; i >= 0; i--)
        {
            ans += cnt[i];
            if (ans >= i)
                return i;
        }
        return 0;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> citations(n);
    for (int i = 0; i < n; i++)
        cin >> citations[i];
    Solution s;
    cout << s.hIndex(citations) << endl;
    return 0;
}