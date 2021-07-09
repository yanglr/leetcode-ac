from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        r = 0
        for i in nums:
            r ^= i
        return r

#以下是测试
sol = Solution()
print(sol.singleNumber([6, 4, 6, 2, 4]))