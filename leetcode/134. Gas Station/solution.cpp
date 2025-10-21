#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ans = 0, n = gas.size(), fuel = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            fuel += gas[i] - cost[i];
            start += gas[i] - cost[i];
            if (start < 0)
            {
                start = 0;
                ans = i + 1;
            }
        }
        return (fuel < 0) ? -1 : ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    Solution S;
    cout << S.canCompleteCircuit(gas, cost) << "\n";
    return 0;
}