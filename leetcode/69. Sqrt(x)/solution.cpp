#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int i = 0;
        while ((long long)i * (long long)i <= (long long)x)
        {
            i++;
        }
        return i - 1;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution S;
    cout << S.mySqrt(n) << endl;
    return 0;
}