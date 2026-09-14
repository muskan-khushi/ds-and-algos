# Allocate Minimum Pages

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]** of integers, where each element  **arr[i]**  represents the number of pages in the i-th book. You also have an integer  **k**  representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- All books must be allocated.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return  **-1** ;

 **Examples:** 

```
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
```

```
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
```

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-14T04:12:36.113Z  

```java
class Solution {
    public int findPages(int[] arr, int k) {
        // code here
        // arr[i] - no of pages in the ith book
        // k - number of students
        
        if (arr.length < k) return -1;
        
        long low = 0;
        long high = 0;
        
        for (int num : arr){
            low = Math.max(num, low);
            high += num;
        }
        
        while (low < high){
            long mid = low + (high-low)/2;
            
            if (canBeSplit(arr, k, mid)) high = mid;
            else low = mid+1;
        }
        return (int)low;
    }
    
    private boolean canBeSplit(int[] arr, int k, long limit){
        int subarrays = 1;
        int currSum = 0;
        
        for (int num : arr){
            if (currSum + num > limit){
                subarrays++;
                currSum = num;
            }
            else currSum += num;
        }
        
        return subarrays <= k;
    }
}
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)