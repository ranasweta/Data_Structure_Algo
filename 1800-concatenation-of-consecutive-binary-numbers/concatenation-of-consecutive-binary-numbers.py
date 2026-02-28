class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 10**9 + 7
        ans = 0
        length = 0
        
        for i in range(1, n + 1):
            # Count bits in i
            length = i.bit_length()
            # Shift ans left and add i
            ans = ((ans << length) | i) % MOD
        
        return ans