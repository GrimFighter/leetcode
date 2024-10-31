class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        # count = 0
        # for i in range(len(nums)):
        #     sum=0
        #     for j in range(i, len(nums)):
        #         sum = sum + nums[j]
        #         if sum == k:
        #             count = count + 1

        # return count

        count = 0
        dic = {0: 1}
        sum = 0

        for num in nums:
            sum += num
            if sum - k in dic:
                count += dic[sum - k]
            if sum not in dic:
                dic[sum] =1
            else:
                dic[sum] +=1

        return count
