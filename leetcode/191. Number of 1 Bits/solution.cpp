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

int main()
{
    SolutionBPC s;
    int n;
    cin >> n;
    cout << s.hammingWeight(n) << endl;
    return 0;
}