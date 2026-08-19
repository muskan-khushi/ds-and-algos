# Count zeros in a sorted matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given a  **n * n** binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of  **zeros**  present in the matrix.

 **Examples:** 

```
Input: mat[][] = [[0,0,0], [0,0,1], [0,1,1]]
 
Output: 6
Explanation: 
The first, second and third row contains 3, 2 and 1
zeroes respectively.
```

```
Input: mat[][] = [[1,1], [1,1]]
 
Output: 0
Explanation:
There are no zeroes in any of the rows.
```

 **Constraints** 
0 < n ≤ 103
0 ≤ mat[i][j] ≤ 1

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-19T13:57:14.153Z  

```cpp
//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int row = 0;
        int col = n-1;
        int count = 0;
        
        while (row < n && col >=0){
            if (mat[row][col] == 0){
                count += col + 1;
                row++;
            }
            else col--;
        }
        return count;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-zeros-in-a-sorted-matrix/1)