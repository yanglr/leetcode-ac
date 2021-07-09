from typing import List

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        B = sorted(A, key = abs) # sort by absolute values
        res = list()
        for elem in B:
            res.append(elem*elem)
        return res

# below is testing        
sol = Solution()
print(sol.sortedSquares([-4,-2, 3,6]))