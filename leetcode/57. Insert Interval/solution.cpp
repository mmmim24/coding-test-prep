#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[1] < intervals[i][0])
            {
                result.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(result));
                return result;
            }
            else if (newInterval[0] > intervals[i][1])
            {
                result.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    vector<int> newInterval(2);
    for (int i = 0; i < n; i++)
    {
        vector<int> interval(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> interval[j];
        }
        intervals[i] = interval;
    }
    cin >> newInterval[0] >> newInterval[1];
    Solution s;
    vector<vector<int>> answer = s.insert(intervals, newInterval);
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