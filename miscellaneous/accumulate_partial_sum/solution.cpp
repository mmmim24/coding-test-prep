#include <bits/stdc++.h>
using namespace std;
int mul(int x, int y)
{
    return x * y;
}
int main()
{
    int n, sum = 0, product = 1;
    cin >> n;
    vector<int> nums(n), prefix_sum(n), prefix_product(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sum = accumulate(nums.begin(), nums.end(), sum);
    product = accumulate(nums.begin(), nums.end(), product, mul);
    partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
    partial_sum(nums.begin(), nums.end(), prefix_product.begin(), mul);
    cout << "the sum is : " << sum << "\n";
    cout << "the product is : " << product << "\n";
    cout << "prefix sum : ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix_sum[i] << " \n"[i == n - 1];
    }
    cout << "prefix product : ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix_product[i] << " \n"[i == n - 1];
    }
    return 0;
}