# Spiral Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` `matrix`, return  *all elements of the*  `matrix`  *in spiral order*.

 

 **Example 1:** 

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

```

 **Example 2:** 

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

```

 

 **Constraints:** 

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 10
- -100 <= matrix[i][j] <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.4 MB (beats 57.55%)  
**Submitted:** 2026-08-24T07:48:43.192Z  

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;

        while (left  <= right && top <= bottom){
            //print top
            for (int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //print right
            for (int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //print bottom
            if (top <= bottom){
            for (int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }

            //print left
            if (left <= right){
            for (int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/spiral-matrix/)