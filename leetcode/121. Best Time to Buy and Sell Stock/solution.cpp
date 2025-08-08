#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, j = 1, profit = 0;
        while (j < prices.size())
        {
            if (prices[i] > prices[j])
                i = j;
            else
                profit = max(profit, prices[j] - prices[i]);
            j++;
        }
        return profit;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution S;
    cout << S.maxProfit(v) << endl;
    return 0;
}
