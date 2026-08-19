# Elements in the Range

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given an array  **arr[]**  containing  **distinct**  positive integers, and two integers  **start**  and  **end**  defining a range. Determine if the array contains all elements within inclusive range  **[start, end]**.

 **Note:**  If the array contains all elements in the given range return  **true** otherwise return  **false.** 

 **Examples :** 

```
Input: start = 2, end = 5, arr[] =  [1, 4, 5, 2, 7, 8, 3]
Output: true
Explanation: All integers within the range [2, 5] are 2, 3, 4, and 5, and all of them are present in the array. Therefore, the answer is true for this test case.

```

```
Input: start = 2, end = 6, arr[] = [1, 4, 5, 2, 7, 8, 3]
Output: false
Explanation: The array does not contain 6; hence, it does not contain all the elements in the range [2, 6]. Therefore, the output is false.

```

 **Constraints:** 
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
0 ≤ start ≤ end ≤ 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-19T13:53:23.918Z  

```cpp
class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n = arr.size();
        unordered_set<int> s(arr.begin(), arr.end());
        
        for (int x = start; x<=end; x++){
            if (s.find(x) == s.end()) return false;
        }
        
        
        return true;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/elements-in-the-range2834/1)