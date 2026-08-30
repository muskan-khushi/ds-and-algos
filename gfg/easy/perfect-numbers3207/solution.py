class Solution:
    def isPerfect(self, n):
        # code here 
        ans = 1
        i = 2
        
        while i*i <= n:
            if n%i == 0:
                ans += i
                
                if i != n//i:
                    ans += n//i
                    
            i+=1
        
        return n==ans