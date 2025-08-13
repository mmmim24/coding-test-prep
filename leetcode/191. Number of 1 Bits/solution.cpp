#include <bits/stdc++.h>
using namespace std;

class SolutionBPC
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }
};
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n)
        {
            if (n & 1)
                result++;
            n >>= 1;
        }
        return result;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.hammingWeight(n) << endl;
    return 0;
}