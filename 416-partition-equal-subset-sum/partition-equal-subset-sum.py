class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)

        if total_sum % 2 != 0:
            return False
        target = total_sum // 2

        dp=[False for _ in range(target+1)]
        dp[0]=True


        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
                
        return dp[target]

       

    # def canPP(self,nums,n,i, target):
    #     if(n == target):
    #         return True
    #     if(i >= len(nums) or n > target):
    #         return False
        
    #     a = self.canPP(nums, n + nums[i], i+1, target)
    #     b = self.canPP(nums, n, i+1, target)

    #     return a or b
        