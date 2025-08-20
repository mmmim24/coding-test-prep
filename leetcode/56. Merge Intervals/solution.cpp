#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (auto interval : intervals)
        {
            int start = interval[0], end = interval[1];
            int prevEnd = result.back()[1];
            if (start <= prevEnd)
                result.back()[1] = max(end, prevEnd);
            else
                result.push_back({start, end});
        }
        return result;
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
    vector<vector<int>> answer = s.merge(intervals);
    cout << "[";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < 2; j++)
        {
            cout << answer[i][j] << ",]"[j == 1];
        }
        cout << ",]"[i == answer.size() - 1];
    }
    return 0;
}