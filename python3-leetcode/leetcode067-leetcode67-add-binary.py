class Solution:
    def addBinary(self, a: str, b: str) -> str:
        num1 = int(a, 2)
        num2 = int(b, 2)
        sum0 = num1 + num2
        return format(sum0, 'b')

# 测试
sol = Solution()
print(sol.addBinary('11', '1101'))