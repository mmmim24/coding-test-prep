class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        i, j, profit = 0, 1, 0
        while j < len(prices):
            if prices[i] > prices[j]:
                i = j
            else:
                profit = max(profit, prices[j] - prices[i])
            j += 1
        return profit

n = int(input())
prices = list(map(int, input().split()))
s = Solution()
print(s.maxProfit(prices))