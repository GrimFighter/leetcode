class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            count+=1
            for j in range(i):
                if self.isP(s[j:i+1]):
                    count+=1
        return count
    def isP(self,s):
        return s == s[::-1]
