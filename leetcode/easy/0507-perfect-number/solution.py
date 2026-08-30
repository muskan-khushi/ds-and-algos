class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1:
            return False

        ans = 1
        i = 2

        while i*i <= num:
            if num%i == 0:
                ans += i

                if i != num//i:
                    ans += num//i
             
            i+=1

        return num == ans