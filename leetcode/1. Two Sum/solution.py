class Solution():
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        num_dict = {}
        for i in range(len(nums)):
            num_dict[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in num_dict and num_dict[complement] != i:
                return [i, num_dict[complement]]
        return []

        

n, target = input().split()
n = int(n)
target = int(target)
nums = list(map(int, input().split()))
sol = Solution()
result = sol.twoSum(nums, target)
print(result[0], result[1])