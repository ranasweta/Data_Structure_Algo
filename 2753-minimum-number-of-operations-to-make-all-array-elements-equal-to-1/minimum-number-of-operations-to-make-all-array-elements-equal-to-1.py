import math

class Solution:
    def minOperations(self, nums):
        gcd_val = nums[0]
        for i in range(len(nums)):
            if nums[i] == 1:
                return sum(1 for x in nums if x != 1)
            if i < len(nums) - 1:
                gcd_val = math.gcd(gcd_val, nums[i + 1])

        if gcd_val != 1:
            return -1

        ans = 10**9
        n = len(nums)
        for i in range(n):
            g = nums[i]
            for j in range(i + 1, n):
                g = math.gcd(g, nums[j])
                if g == 1:
                    ans = min(ans, j - i - 1 + n)
                    break
        return ans