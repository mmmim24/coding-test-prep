class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        i, j = 0, len(s) - 1
        while i < j:
            if self.isalnum(s[i]) and self.isalnum(s[j]):
                if s[i].lower() != s[j].lower():
                    return False
                else:
                    i += 1
                    j -= 1
            else:
                if not self.isalnum(s[i]):
                    i += 1
                if not self.isalnum(s[j]):
                    j -= 1
        return True
    def isalnum(self, c: str) -> bool:
        return (ord('a') <= ord(c) <= ord('z') or
                ord('A') <= ord(c) <= ord('Z') or
                ord('0') <= ord(c) <= ord('9')
                )

string = input()
s = Solution()
print(s.isPalindrome(string))