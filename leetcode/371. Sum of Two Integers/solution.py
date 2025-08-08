class Solution:
    def getSum(a:int, b:int)->int:
        sum = a ^ b
        carry = (a & b) << 1
        while not carry ==0:
            a = sum
            b = carry
            sum = a ^ b 
            carry = (a & b) << 1
        return sum

a,b = input().split(' ')
a = int(a)
b = int(b)
S = Solution
print(S.getSum(a,b))
        