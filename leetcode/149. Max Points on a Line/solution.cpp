#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int ans = 0, n = points.size();
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            double x1, y1, x2, y2, slope;
            x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else
                {
                    x2 = points[j][0], y2 = points[j][1];
                    if (x2 == x1)
                    {
                        slope = INT_MAX;
                    }
                    else
                    {
                        slope = ((y2 - y1) * 1.0) / (x2 - x1);
                    }
                    mp[slope]++;
                    ans = max(ans, mp[slope]);
                }
            }
        }
        return ans + 1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        vector<int> p(2);
        cin >> p[0] >> p[1];
        points.push_back(p);
    }
    Solution s;
    cout << s.maxPoints(points) << endl;
    return 0;
}