class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        nums.sort()
        
        def exists(nums, x):
            l, r = 0, len(nums) - 1
            while l <= r:
                mid = l + (r - l) // 2
                if nums[mid] == x:
                    return True
                elif nums[mid] < x:
                    l = mid + 1
                else:
                    r = mid - 1
            return False

        while exists(nums, original):
            original *= 2
        return original