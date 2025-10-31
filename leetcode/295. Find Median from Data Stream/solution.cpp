#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
private:
    priority_queue<int, vector<int>, less<int>> large;
    priority_queue<int, vector<int>, greater<int>> small;
    double md = 0;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        small.push(num);
        if (!large.empty() && small.top() > large.top())
        {
            large.push(small.top());
            small.pop();
        }
        if (small.size() > large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        if (large.size() > small.size() + 1)
        {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        if (small.size() > large.size())
            md = small.top();
        else if (small.size() < large.size())
            md = large.top();
        else
            md = (small.top() + large.top()) / 2.0;
        return md;
    }
};
int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    cout << obj->findMedian() << endl;
    obj->addNum(5);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}