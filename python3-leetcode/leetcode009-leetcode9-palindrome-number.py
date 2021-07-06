class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            str0 = str(x)
            reversedStr = str0[::-1]
            if reversedStr == str0:
                return True
        return False
        
# Below is testing
sol = Solution()
print(sol.isPalindrome(616))