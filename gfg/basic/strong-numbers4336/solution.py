class Solution:
    def isStrong(self, n):
        # code here
        s = str(n)
        ans = 0
        
        for ch in s:
            digit = int(ch)
            fact = 1
            for i in range(1,digit+1):
                fact*=i
            ans += fact
            
        return ans == n