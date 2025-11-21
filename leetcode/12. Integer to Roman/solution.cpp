#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};
        ans = thousands[(num / 1000) % 10] + hundreds[(num / 100) % 10] + tens[(num / 10) % 10] + ones[num % 10];
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.intToRoman(n) << endl;
    return 0;
}