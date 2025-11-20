#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> vpp;
        for (int i = 0; i < n; i++)
            vpp.push_back({capital[i], profits[i]});

        sort(vpp.begin(), vpp.end());
        priority_queue<int> maxHeap;
        int it = 0;

        for (int i = 0; i < k; i++)
        {
            while (w >= vpp[it].first && it < n)
            {
                maxHeap.push(vpp[it].second);
                it++;
            }

            if (maxHeap.empty())
                break;

            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
int main()
{
    int n, k, w;
    cin >> n >> k >> w;
    vector<int> profits(n), capital(n);
    for (int i = 0; i < n; i++)
        cin >> profits[i];
    for (int i = 0; i < n; i++)
        cin >> capital[i];
    Solution s;
    cout << s.findMaximizedCapital(k, w, profits, capital);
    return 0;
}