class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        else:
            isDelete = [False]*n
            max0 = int(math.sqrt(n))
            count = 0
            for i in range(2, n):
                if isDelete[i] == True:
                    continue
                count += 1

                if i > max0:
                    continue

                for j in range(i*i, n, i):
                    isDelete[j] = True
        return count  