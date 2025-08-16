#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // O(n) time complexity
    unordered_set<int> ust(nums.begin(), nums.end());
    // O(n log n) time complexity
    set<int> st(nums.begin(), nums.end());
    for (auto element : ust)
    {
        cout << element << " ";
    }
    cout << endl;
    for (auto element : st)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}