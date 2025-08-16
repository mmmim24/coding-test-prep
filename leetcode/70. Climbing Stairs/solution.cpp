#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bottomUp(int n)
    {
        int dp[n + 1];
        if (n > 0)
            dp[1] = 1;
        if (n > 1)
            dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
    int climbStairs(int n)
    {
        return bottomUp(n);
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}