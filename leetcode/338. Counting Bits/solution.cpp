#include <bits/stdc++.h>
using namespace std;
class SolutionPopCount
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++)
        {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};
class Solution2
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1); // quotient and remainder
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> countBits(int n)
    {
        int offset = 1;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == offset << 1)
                offset = i;
            ans[i] = 1 + ans[i - offset];
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution2 s;
    vector<int> ans = s.countBits(n);
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}