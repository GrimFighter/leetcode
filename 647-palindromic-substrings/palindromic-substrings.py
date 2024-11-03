class Solution:
    # def countSubstrings(self, s: str) -> int:
    #     count = 0
    #     for i in range(len(s)):
    #         count+=1
    #         for j in range(i):
    #             if self.isP(s[j:i+1]):
    #                 count+=1
    #     return count
    # def isP(self,s):
    #     return s == s[::-1]

    def countSubstrings(self, s: str) -> int:
        count = 0

        for i in range(len(s)):
            count += self.expand(s, i, i)
            count += self.expand(s, i, i + 1)
        return count

    def expand(self, s, l, r):
        count = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        return count
