#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for (int j = 0; j < coins.size(); j++)
        {
            for (int i = coins[j]; i <= amount; i++)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
int main()
{
    int n, amount;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> amount;
    Solution s;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}