# -*- coding: utf-8 -*-
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        d = dict()
        for num in nums:
            if num not in d:
                d[num] = 1
            else:
                d[num] += 1
        res = next(k for k, val in d.items() if val == 1)
        return res

#以下是测试
sol = Solution()
print(sol.singleNumber([6, 4, 6, 2, 4]))