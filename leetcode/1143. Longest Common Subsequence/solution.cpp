#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2)
    {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text2, 0, 0);
    }

private:
    int lcs(string text1, string text2, int i, int j)
    {
        if (i == text1.size() || j == text2.size())
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (text1[i] == text2[j])
            memo[i][j] = 1 + lcs(text1, text2, i + 1, j + 1);
        else
            memo[i][j] = max(lcs(text1, text2, i + 1, j), lcs(text1, text2, i, j + 1));
        return memo[i][j];
    }
};
int main()
{
    string a, b;
    cin >> a >> b;
    cout << Solution().longestCommonSubsequence(a, b) << endl;
    return 0;
}