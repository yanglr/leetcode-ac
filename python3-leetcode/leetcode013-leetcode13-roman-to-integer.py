class Solution:
    def romanToInt(self, s: str) -> int:
        d = dict()
        d = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        sum0 = 0
        for i in range(len(s)):
            currentValue = d[s[i]]
            
            if i == len(s) -1 or d[s[i+1]] <= currentValue:  # d[s[i+1]]: nextValue
                sum0 += d[s[i]]
            else:
                sum0 -= d[s[i]]
        
        return sum0

sol = Solution()
print(sol.romanToInt("MCMXCIV"))