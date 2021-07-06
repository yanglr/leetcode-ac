from typing import List
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        if (len(A) < 3):
            return 0

        A.sort(reverse=True)
        for i in range(len(A)-2):
            if A[i] < A[i+1] + A[i+2]:  # Can build a triangle
                return A[i] + A[i+1] + A[i+2]
        return 0

# Below is testing
sol = Solution()
print(sol.largestPerimeter([4, 5, 2, 7]))