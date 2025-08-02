n = int(input())
nums = list(map(int, input().split()))
class Solution:
    def hasDuplicate(self, nums):
        return len(nums) != len(set(nums))
    
solution = Solution()
result = solution.hasDuplicate(nums)
print(result)