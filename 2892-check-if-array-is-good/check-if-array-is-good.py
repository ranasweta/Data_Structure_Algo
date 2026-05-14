class Solution:
    def isGood(self, nums: List[int]) -> bool:
        nums.sort()
        if len(nums)!=nums[-1]+1:
            return False

        for i in range(1,len(nums)):
            if nums[i-1]!=i:
                return False
        return nums[-1]==nums[-2]

        