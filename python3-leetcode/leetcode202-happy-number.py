class Solution:
    def isHappy(self, n: int) -> bool:
        unhappy = set()
        while n not in unhappy and n != 1:
            unhappy.add(n)
            n = self.GetSquareSum(n)
        return n == 1    

    def GetSquareSum(self, n: int) -> bool:
        sum0 = 0
        while n > 0:
            r = n - int(n/10)*10
            n = int(n/10)
            sum0 += r * r
        return sum0

sol = Solution()
print(sol.isHappy(19))