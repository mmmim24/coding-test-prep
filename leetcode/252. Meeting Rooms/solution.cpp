#include <bits/stdc++.h>
using namespace std;
class Interval
{
public:
    int start, end;
    Interval()
    {
        this->start = 0;
        this->end = 0;
    }
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};
class Solution
{
public:
    static bool compare(Interval a, Interval b)
    {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
};
int main()
{
    int n;
    cin >> n;

    // use push_back or emplace_back

    // vector<Interval> intervals;
    // for(int i = 0;i<n;i++){
    //     int x,y;
    //     cin>>x>>y;

    //     // any of the following will work

    //     intervals.push_back(Interval(x,y));
    //     intervals.push_back({x,y});
    //     intervals.emplace_back(x,y);

    //     // this will not work as size is not predefined

    //     intervals[i] = Interval(x, y);
    //     intervals[i].start = x;
    //     intervals[i].end = y;
    // }

    // for predefining size, default constructor will be called

    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].start >> intervals[i].end;
    }
    Solution sol;
    cout << sol.canAttendMeetings(intervals) << endl;
    return 0;
}