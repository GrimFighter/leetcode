class Solution:
    def longestPalindrome(self, s: str) -> str:

        def isPalinDrome(s):
            return s == s[::-1]

        result = ""
        length = 0

        for i in range(len(s)):
            for j in range(len(s), i, -1):
                if isPalinDrome(s[i:j]):
                    if len(s[i:j]) > length:
                        length = len(s[i:j])
                        result = s[i:j]

        return result
