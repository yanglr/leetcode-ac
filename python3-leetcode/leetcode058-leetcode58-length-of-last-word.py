class Solution:
    def lengthOfLastWord(self, s: str) -> int: 
        newStr = s.strip()       
        lastSpacePos = newStr.rfind(' ')
        if lastSpacePos == -1:
            return len(newStr)
        else:
            return len(newStr) - lastSpacePos - 1

sol = Solution()
print(sol.lengthOfLastWord('Hello my baby'))