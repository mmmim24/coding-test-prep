#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int res = 0, prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prevEnd)
            {
                res++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }
        return res;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> interval(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> interval[j];
        }
        intervals[i] = interval;
    }
    Solution s;
    s.eraseOverlapIntervals(intervals);
    cout << s.eraseOverlapIntervals(intervals) << endl;
    cout << "[";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < 2; j++)
        {
            cout << intervals[i][j] << ",]"[j == 1];
        }
        cout << ",]"[i == intervals.size() - 1];
    }
    return 0;
}