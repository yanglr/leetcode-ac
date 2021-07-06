from typing import List

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        res = list()
        nums.sort()
        stdList = range(1, len(nums) + 1)  # len(nums) = n
        repeatedNum = sum(nums) - sum(set(nums))     
        res.append(repeatedNum)
        missingNum =  (set(stdList) - set(nums)).pop()
        res.append(missingNum)
        return res
        
# below is testing        
sol = Solution()
print(sol.findErrorNums([4,2, 1,2]))
