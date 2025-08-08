import java.util.Scanner;
import static java.lang.Math.max;

class Solution{

    public int maxProfit(int[] prices){
        int i = 0, j = 1, profit = 0;
        while (j < prices.length)
        {
            if (prices[i] > prices[j])
                i = j;
            else
                profit = max(profit, prices[j] - prices[i]);
            j++;
        }
        return profit;
    }

    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++)
            prices[i] = sc.nextInt();
        Solution sol = new Solution();
        System.out.println(sol.maxProfit(prices));
        sc.close();
    }
}