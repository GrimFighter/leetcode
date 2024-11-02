class Solution:
    def rob(self, nums: List[int]) -> int:
        self.dp = [-1 for _ in range(len(nums))]

        return self.robp(nums, len(nums) - 1)

    def robp(self, nums, i):
        if i < 0:
            return 0
        if self.dp[i] >= 0:
            return self.dp[i]
        res = max(self.robp(nums, i - 2) + nums[i], self.robp(nums, i - 1))
        self.dp[i] = res
        return self.dp[i]
