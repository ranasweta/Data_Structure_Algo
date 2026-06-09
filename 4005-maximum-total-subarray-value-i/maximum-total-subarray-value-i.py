class Solution:#easy
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        minElement=min(nums)
        maxElement=max(nums)
        return (maxElement-minElement)*k
        
        