class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(len(s)):
            if stack == []:
                stack.append(s[i])
            else:
                top = stack[-1]
                if (top == '(' and s[i] == ')') or (top == '{' and s[i] == '}') or (top == '[' and s[i] == ']'):
                    stack.pop()
                else:
                    stack.append(s[i])
        return stack == []

sol = Solution()
s = input()
print(sol.isValid(s))