#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int j = 1, profit = 0;
        while (j < prices.size())
        {
            if (prices[j] > prices[j - 1])
                profit += prices[j] - prices[j - 1];
            j++;
        }
        return profit;
    }
};

int main()
{
    int n;
    vector<int> v;
    while (cin >> n)
    {
        v.push_back(n);
    }
    Solution S;
    cout << S.maxProfit(v) << endl;
    return 0;
}
