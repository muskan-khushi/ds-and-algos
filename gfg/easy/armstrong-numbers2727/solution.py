class Solution:
    def armstrongNumber (self, n):
        # code here 
        s = str(n)
        power = len(s)
        ans = 0
        
        for digit in s:
            ans += int(digit)**power
            
        return n == ans