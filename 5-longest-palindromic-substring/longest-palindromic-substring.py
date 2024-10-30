class Solution:
    def longestPalindrome(self, s: str) -> str:

        def isPalinDrome(s):
            return s == s[::-1]

        # result = ""
        # length = 0

        # for i in range(len(s)):
        #     for j in range(len(s), i, -1):
        #         if isPalinDrome(s[i:j]):
        #             if len(s[i:j]) > length:
        #                 length = len(s[i:j])
        #                 result = s[i:j]

        # return result
        if (len(s)) <= 1:
            return s

        if isPalinDrome(s):
            return s

        length = 1
        result = s[0]

        dp = [[False for _ in range(len(s))] for _ in range(len(s))]

        for i in range(len(s)):
            dp[i][i] = True
            for j in range(i):
                if s[j] == s[i] and (i - j <= 2 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                    if i - j + 1 > length:
                        length = i - j + 1
                        result = s[j : i + 1]

        return result

