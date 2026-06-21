# 🧭 Two Pointer Technique — Complete Study Notes
### Data Structures & Algorithms | Beginner → Expert

---

> **What is this?**
> The Two Pointer technique is a pattern where you maintain **two index variables** that move through a data structure in a coordinated way — so you solve problems that would normally need nested loops in a single pass.
>
> Think of it like two people walking toward each other on a bridge — they start at opposite ends and meet in the middle. Each step either person takes is guided by what they both see together.

---

## 📌 Table of Contents

1. [When to Use Two Pointers](#1-when-to-use-two-pointers)
2. [Two Sum — The Foundation](#2-two-sum--the-foundation)
3. [Remove Duplicates from Sorted Array](#3-remove-duplicates-from-sorted-array)
4. [Squares of a Sorted Array](#4-squares-of-a-sorted-array)
5. [Merge Two Sorted Arrays](#5-merge-two-sorted-arrays)
6. [Three Sum (Triplet Sum = 0)](#6-three-sum-triplet-sum--0)
7. [3Sum Closest](#7-3sum-closest)
8. [Triplets Smaller Than Sum](#8-triplets-smaller-than-sum)
9. [Two Sum — No Duplicate Pairs](#9-two-sum--no-duplicate-pairs)
10. [Dutch National Flag Problem](#10-dutch-national-flag-problem)
11. [Time & Space Complexity Guide](#11-time--space-complexity-guide)
12. [Master Revision Sheet](#12-master-revision-sheet)

---

## 1. When to Use Two Pointers

Before jumping to code, ask yourself these questions:

```
Is the input an Array or Linked List?         ✅ YES → Two Pointer might work
       ↓
Is it sorted, or can we sort it?              ✅ YES → Very likely Two Pointer
       ↓
Do we need to find pairs / triplets?          ✅ YES → Classic Two Pointer
       ↓
Do we need to rearrange / merge in-place?     ✅ YES → Two Pointer with no extra space
       ↓
Is cycle detection involved?                  ✅ YES → Fast & Slow Pointer (Floyd's)
```

### Quick Trigger Table

| Situation | Apply Two Pointer? |
|---|---|
| Array + sorted + find pair summing to target | ✅ Yes |
| Array + find index (cannot sort) | ❌ No → use HashMap |
| Remove duplicates in-place | ✅ Yes |
| Merge two sorted arrays | ✅ Yes |
| Rearrange without extra space | ✅ Yes |
| Detect cycle in linked list | ✅ Yes (fast/slow) |
| Find subarrays with sum | ✅ Sliding window (variant) |

### ⚠️ The Critical Sorting Rule

```
Finding a NUMBER?  →  Sort the array → use Two Pointer ✅
Finding an INDEX?  →  Do NOT sort (you'd lose original positions) → use HashMap ✅
```

---

## 2. Two Sum — The Foundation

### 🧩 Problem
Given an array and a target, find two numbers `a` and `b` such that `a + b = target`. Return their indices (or values).

---

### Approach 1 — Brute Force 🐢

Check every possible pair.

```
for i = 0 to n:
    for j = 0 to n:
        if arr[i] + arr[j] == target:
            return (i, j)
```

```
Array: [2, 7, 11, 15]   Target = 9

Check: 2+7=9 ✅  → done

But worst case: we check ALL pairs → O(n²)
```

**Time:** O(n²) | **Space:** O(1)

**Why it's bad:** For n = 10,000, that's 100 million comparisons. Too slow.

---

### Approach 2 — HashMap 🗺️

Store each number's index in a map. For every element, check if its complement (`target - arr[i]`) already exists.

```
Target = 9
arr = [2, 7, 11, 15]

Step 1: map = {2: 0}         → need 7, not in map yet
Step 2: map = {2:0, 7:1}     → need 2, 2 IS in map! → return (0, 1)
```

**Pseudocode:**
```
map = {}
for i = 0 to n:
    complement = target - arr[i]
    if complement in map:
        return (map[complement], i)
    map[arr[i]] = i
```

**Time:** O(n) | **Space:** O(n)

**Memory cost reality check:**
```
10⁴ elements  →  ~1.6 MB  ✅ fine
10⁹ elements  →  ~16 GB   ❌ not fine — avoid space at large n
```

> **Rule:** Using space is the last option. If a no-space solution exists, prefer it.

---

### Approach 3 — Two Pointer (Optimal) ✅

**Precondition: array must be sorted** (or we sort it).

```
Before sort: [2, 5, 1, 7, 3]   Target = 6
After sort:  [1, 2, 3, 5, 7]
              i           j
```

**The Logic:**
```
sum = arr[i] + arr[j]

if sum == target  →  🎉 found it!
if sum < target   →  need bigger sum  →  move i right (i++)
if sum > target   →  need smaller sum →  move j left  (j--)
```

**Stop when:** `i >= j` (pointers have met or crossed)

**Pseudocode:**
```
sort(array)
i = 0
j = n - 1

while (i < j):
    sum = arr[i] + arr[j]

    if sum == target:
        return (i, j)
    else if sum < target:
        i++
    else:
        j--

return -1   ← no pair found
```

**Full Dry Run:**
```
Array (sorted): [1, 2, 3, 5, 7]   Target = 6
                 0  1  2  3  4

Step 1: i=0(1), j=4(7) → sum = 8 > 6  → j--
Step 2: i=0(1), j=3(5) → sum = 6 = 6  → ✅ return (0, 3) → values (1, 5)
```

**Time:** O(n log n) — sort dominates | **Space:** O(1)

---

### Why Two Pointer Works Here (The Intuition)

```
Sorted: [1, 2, 3, 5, 7]

Imagine a grid of all sums:
       1   2   3   5   7
  1  [ 2   3   4   6   8 ]
  2  [ 3   4   5   7   9 ]
  3  [ 4   5   6   8  10 ]
  5  [ 6   7   8  10  12 ]
  7  [ 8   9  10  12  14 ]

Starting at top-right corner (arr[0] + arr[n-1]):
  - Too big?  Move left  (smaller right element)
  - Too small? Move down (bigger left element)
  
We navigate this grid in O(n) instead of scanning all O(n²) cells.
```

---

## 3. Remove Duplicates from Sorted Array

### 🧩 Problem
Given a sorted array, remove duplicates **in-place** and return the count of unique elements. No extra space allowed.

```
Input:  [1, 1, 1, 2, 2, 3, 3]
Output: [1, 2, 3, _, _, _, _]   → return 3
```

---

### Brute Force ❌
Use 3 separate arrays for 0s, 1s, 2s, then merge. **SC: O(n)** — violates the constraint.

---

### Optimal — Two Pointer ✅

**The two pointer roles:**
```
officer (write head) → points to the last confirmed unique position
cm (current mover)   → scans forward looking for new unique elements
```

**Rule:** If `arr[cm]` is different from `arr[cm-1]`, it's a new unique value — write it.

**Pseudocode:**
```
officer = 0     ← last written position
res = 1         ← first element always unique
cm = 1          ← scanner starts from index 1

while cm < n:
    if arr[cm] == arr[cm-1]:    ← duplicate, skip it
        cm++
        continue

    ← unique element found!
    arr[officer + 1] = arr[cm]
    officer++
    res++
    cm++

return res
```

**Full Dry Run:**
```
Array: [1, 1, 1, 2, 2, 3, 3]
        0  1  2  3  4  5  6

Initial: officer=0, res=1, cm=1

cm=1: arr[1]=1 == arr[0]=1  → duplicate, skip       cm=2
cm=2: arr[2]=1 == arr[1]=1  → duplicate, skip       cm=3
cm=3: arr[3]=2 ≠  arr[2]=1  → UNIQUE!
      arr[officer+1] = arr[3]  →  arr[1] = 2
      officer=1, res=2         cm=4

cm=4: arr[4]=2 == arr[3]=2  → duplicate, skip       cm=5
cm=5: arr[5]=3 ≠  arr[4]=2  → UNIQUE!
      arr[officer+1] = arr[5]  →  arr[2] = 3
      officer=2, res=3         cm=6

cm=6: out of bounds → stop

Array now: [1, 2, 3, 2, 2, 3, 3]  (only first 3 matter)
return 3  ✅
```

**Time:** O(n) | **Space:** O(1)

---

## 4. Squares of a Sorted Array

### 🧩 Problem
Given a sorted array (may have negatives), return a **sorted** array of their squares.

```
Input:  [-4, -1,  0,  3, 10]
Output: [ 0,  1,  9, 16, 100]
```

---

### Why Is This Tricky?

```
Input:  [-4, -1, 0, 3, 10]   ← sorted ✅
Squares: [16,  1, 0, 9, 100] ← NOT sorted ❌
```

Negatives, when squared, become large numbers and "jump" to the end. So just squaring breaks the order.

---

### Brute Force
Square everything → sort → **TC: O(n log n), SC: O(n)**

> We want O(n). We need to eliminate the sort.

---

### Key Insight for O(n) Solution

```
The largest squares ALWAYS come from one of the two ends:
  [-4, -1, 0, 3, 10]
   ↑                ↑
 (-4)²=16       (10)²=100   ← both are large

Compare both ends, take the bigger square, fill result from RIGHT to LEFT.
```

**Two Pointer Approach:**
```
i = 0 (left end)
j = n-1 (right end)
pos = n-1 (fill result from the back)
result = array of size n

while i <= j:
    sq_left  = arr[i] * arr[i]
    sq_right = arr[j] * arr[j]

    if sq_left > sq_right:
        result[pos] = sq_left
        i++
    else:
        result[pos] = sq_right
        j--
    pos--
```

**Dry Run:**
```
arr: [-4, -1, 0, 3, 10]   result: [_, _, _, _, _]
      i=0              j=4        pos=4

Step 1: sq_left=16, sq_right=100 → 100 bigger → result[4]=100, j=3, pos=3
Step 2: sq_left=16, sq_right=9   → 16 bigger  → result[3]=16,  i=1, pos=2
Step 3: sq_left=1,  sq_right=9   → 9 bigger   → result[2]=9,   j=2, pos=1
Step 4: sq_left=1,  sq_right=0   → 1 bigger   → result[1]=1,   i=2, pos=0
Step 5: sq_left=0,  sq_right=0   → equal       → result[0]=0,   j=1, pos=-1

Result: [0, 1, 9, 16, 100]  ✅
```

**Time:** O(n) | **Space:** O(n) — output array required

---

### Alternative: Split + Merge Approach

**Step 1:** Walk through array, split into:
```
a = negatives squared: [16, 4, 1]   (reverse sorted)
b = non-negatives squared: [0, 9, 100]  (already sorted)
```

**Step 2:** Reverse `a` → `[1, 4, 16]`

**Step 3:** Merge two sorted arrays → `[0, 1, 4, 9, 16, 100]`

This also gives **TC: O(n), SC: O(n)** and is conceptually simpler.

---

## 5. Merge Two Sorted Arrays

### 🧩 Problem
Merge arrays `a[n]` and `b[m]` into a single sorted array. (Used as a subroutine in many problems.)

```
a: [1, 3, 5]     b: [2, 4, 6]
→  result: [1, 2, 3, 4, 5, 6]
```

**Pseudocode:**
```
i = 0, j = 0, id = 0
result = array of size (n + m)

while i < n and j < m:
    if a[i] <= b[j]:
        result[id++] = a[i++]
    else:
        result[id++] = b[j++]

← drain leftover elements
while j < m: result[id++] = b[j++]
while i < n: result[id++] = a[i++]

return result
```

**Dry Run:**
```
a: [1, 3, 5]   b: [2, 4, 6]
    i=0             j=0

a[0]=1 ≤ b[0]=2  → res[0]=1, i=1
a[1]=3 > b[0]=2  → res[1]=2, j=1
a[1]=3 ≤ b[1]=4  → res[2]=3, i=2
a[2]=5 > b[1]=4  → res[3]=4, j=2
a[2]=5 ≤ b[2]=6  → res[4]=5, i=3
i exhausted → drain b: res[5]=6

Result: [1, 2, 3, 4, 5, 6]  ✅
```

**Time:** O(n + m) → O(n) | **Space:** O(n)

---

## 6. Three Sum (Triplet Sum = 0)

### 🧩 Problem
Find all **unique** triplets in the array that sum to zero.

```
Input:  [-1, 0, 1, 2, -1, 4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

---

### Brute Force — O(n³) 🐢

```
for i = 0 to n:
  for j = i+1 to n:
    for k = j+1 to n:
      if arr[i] + arr[j] + arr[k] == 0:
        store triplet
```

For n = 1000, this is 10⁹ operations. Way too slow.

---

### Optimised — Sort + Loop + Two Pointer ✅

**Core Idea:**
```
Fix one element arr[i].
Now we need: x + y = -arr[i]   (two sum!)
Use two pointers on the rest of the array.
```

```
Sort the array.

for i = 0 to n-2:

    ← skip duplicates for i
    if i > 0 and arr[i] == arr[i-1]: continue

    left  = i + 1
    right = n - 1

    while left < right:
        s = arr[i] + arr[left] + arr[right]

        if s == 0:
            store [arr[i], arr[left], arr[right]]
            left++
            right--
            ← skip duplicates for left
            while left < right and arr[left] == arr[left-1]: left++
            ← skip duplicates for right
            while right > 0 and arr[right] == arr[right+1]: right--

        else if s < 0:
            left++    ← need bigger sum
        else:
            right--   ← need smaller sum
```

**Dry Run:**
```
Input: [-1, 0, 1, 2, -1, 4]
Sorted: [-1, -1, 0, 1, 2, 4]
          0   1  2  3  4  5

i=0: arr[0]=-1  →  need pair summing to 1
     left=1(-1), right=5(4)  →  s=-1+4=3  > 1  →  right--
     left=1(-1), right=4(2)  →  s=-1+2=1  = 1  ✅ store [-1,-1,2]
                                                    left++, right--
     left=2(0),  right=3(1)  →  s=0+1=1   = 1  ✅ store [-1,0,1]
                                                    left++, right--
     left=3 ≥ right=3        →  stop inner loop

i=1: arr[1]=-1 == arr[0]=-1  →  duplicate! skip

i=2: arr[2]=0  →  need pair summing to 0
     left=3(1), right=5(4)   →  s=1+4=5  > 0  →  right--
     left=3(1), right=4(2)   →  s=1+2=3  > 0  →  right--
     left=3 ≥ right=3        →  stop

Final output: [[-1,-1,2], [-1,0,1]]  ✅
```

**Time:** O(n²) — outer loop O(n) × inner two-pointer O(n) | **Space:** O(1)

---

## 7. 3Sum Closest

### 🧩 Problem
Find 3 numbers whose sum is **closest** to a given target. Return the sum.

```
Input: [-1, 2, 1, -4]   Target = 1
Output: 2   (because -1+2+1=2, closest to 1)
```

---

### Algorithm

```
sort(array)
max_diff = ∞
result_sum = 0

for i = 0 to n-1:
    left = i+1
    right = n-1

    while left < right:
        s = arr[i] + arr[left] + arr[right]
        diff = abs(s - target)

        if diff < max_diff:        ← new closest found
            max_diff = diff
            result_sum = s

        if s == target:
            return s               ← perfect match, can't do better

        else if s < target:
            left++                 ← need bigger sum
        else:
            right--                ← need smaller sum

return result_sum
```

**Key difference from 3Sum:** Instead of checking `== 0`, we track the minimum absolute difference.

**Time:** O(n²) | **Space:** O(1)

---

## 8. Triplets Smaller Than Sum

### 🧩 Problem
Count all unique triplets `(i, j, k)` where `arr[i] + arr[j] + arr[k] < given_sum`.

```
Input: [-2, 0, 1, 3]   Sum = 2
```

---

### The Clever Trick 💡

When `arr[i] + arr[left] + arr[right] < sum`:

```
Array (sorted): [-2, 0, 1, 3]   i=0(-2), left=1(0), right=3(3)
                                  sum = -2+0+3 = 1 < 2  ✅

Since the array is sorted, EVERY element between left and right
pairs with arr[i] and arr[left] to give a valid triplet:
  (-2, 0, 3), (-2, 0, 1)   ← all valid!

So we add (right - left) at once instead of checking one by one!
```

**Algorithm:**
```
sort(array)
ans = 0

for i = 0 to n-2:
    left  = i + 1
    right = n - 1

    while left < right:
        s = arr[i] + arr[left] + arr[right]

        if s >= sum:
            right--                ← too big, shrink from right

        else:                      ← s < sum: all (left+1 to right) also valid!
            ans += (right - left)
            left++

return ans
```

**Example Walkthrough:**
```
Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]   target = 15

i=0(1), left=1(2), right=8(9):
  s = 1+2+9 = 12 < 15 → ans += (8-1) = 7, left++
  s = 1+3+9 = 13 < 15 → ans += (8-2) = 6, left++
  s = 1+4+9 = 14 < 15 → ans += (8-3) = 5, left++
  s = 1+5+9 = 15 ≥ 15 → right--
  ...
```

**Time:** O(n²) | **Space:** O(1)

---

## 9. Two Sum — No Duplicate Pairs

### 🧩 Problem
Find all unique pairs that sum to target. No repeated pairs in output.

```
Input: [1, 1, 1, 2, 2, 3, 3, 3]   Target = 4
Output: {(1, 3)}   ← only once, not 9 times!
```

**The trick:** After storing a valid pair, skip over all duplicates of both `arr[left]` and `arr[right]`.

```
sort(array)
left = 0
right = n - 1

while left < right:
    s = arr[left] + arr[right]

    if s == target:
        store pair (arr[left], arr[right])
        left++
        right--
        ← skip duplicates
        while left < right and arr[left] == arr[left-1]: left++
        while right ≥ 0 and arr[right] == arr[right+1]: right--

    else if s < target:
        left++
    else:
        right--
```

**Dry Run:**
```
[1, 1, 1, 2, 2, 3, 3, 3]   Target = 4
 0  1  2  3  4  5  6  7
 L                       R

Step 1: 1+3=4 ✅ store (1,3), left++, right--
Step 2: left=1: arr[1]==arr[0] → skip, left=2
        right=6: arr[6]==arr[7] → skip, right=5
Step 3: left=2(1), right=5(3) → left < right, but arr[2]=1, arr[5]=3
        1+3=4 ✅... wait, arr[2]==arr[1] → already skipped, so left moves to 3
Step 4: left=3(2), right=5(3) → 2+3=5 ≠ 4 → right--
Step 5: left=3(2), right=4(2) → 2+2=4 ✅ store (2,2)
        left++, right-- → left=4, right=3 → left ≥ right → stop

Pairs: (1,3), (2,2)  ✅
```

---

## 10. Dutch National Flag Problem

### 🧩 Problem
Rearrange an array of `0`s, `1`s, and `2`s **in-place** in a single pass, without sorting.

```
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

---

### Why Not Just Sort?

Sorting is O(n log n). We can do this in O(n) with O(1) space — one pass. This is called **Dijkstra's Dutch National Flag algorithm**.

---

### Approach 1 — Brute (3 arrays) ❌

Collect 0s, 1s, 2s into separate arrays → merge back.
**TC: O(n), SC: O(n)** — uses extra space.

---

### Approach 2 — Count Sort (2 passes)

Count occurrences: `zeros=k, ones=m, twos=p`
Overwrite: fill k zeros, then m ones, then p twos.
**TC: O(n), SC: O(1)** — but requires two passes.

---

### Approach 3 — Dutch National Flag (Best) ✅

**3 pointers divide the array into 4 zones:**

```
[  0s zone  |  1s zone  |  UNKNOWN  |  2s zone  ]
 0         low         mid         high        n-1
```

```
low  = 0     ← boundary between 0s and 1s
mid  = 0     ← current element being examined
high = n-1   ← boundary between unknowns and 2s
```

**Rules at each step:**

```
arr[mid] == 0:  swap(arr[low], arr[mid])
                low++, mid++         ← both regions confirmed, move both

arr[mid] == 1:  mid++                ← 1 is already in right place

arr[mid] == 2:  swap(arr[mid], arr[high])
                high--               ← DON'T move mid!
                                       (swapped value is unknown)
```

**Stop when:** `mid > high` (unknown zone is empty)

---

**Full Dry Run:**

```
Input: [2, 0, 2, 1, 1, 0]
        0  1  2  3  4  5
low=0, mid=0, high=5

Step 1: arr[mid=0]=2  →  swap(arr[0], arr[5]) → [0, 0, 2, 1, 1, 2]
                          high=4  (mid stays at 0)

Step 2: arr[mid=0]=0  →  swap(arr[0], arr[0]) → no change
                          low=1, mid=1

Step 3: arr[mid=1]=0  →  swap(arr[1], arr[1]) → no change
                          low=2, mid=2

Step 4: arr[mid=2]=2  →  swap(arr[2], arr[4]) → [0, 0, 1, 1, 2, 2]
                          high=3  (mid stays at 2)

Step 5: arr[mid=2]=1  →  mid=3

Step 6: arr[mid=3]=1  →  mid=4

Step 7: mid=4 > high=3  →  STOP ✅

Result: [0, 0, 1, 1, 2, 2]  ✅
```

**Why don't we `mid++` when `arr[mid] == 2`?**

```
When we swap arr[mid] with arr[high], the element that just landed at arr[mid]
came from arr[high] — it could be ANYTHING (0, 1, or 2).
We haven't checked it yet! So we must examine it in the next iteration.
If we did mid++, we'd skip an unchecked element.
```

**Time:** O(n) | **Space:** O(1)

---

## 11. Time & Space Complexity Guide

### What Does O(n) Actually Mean?

```
LeetCode / GFG graders allow ~10⁸ simple operations per second.

"Simple operation" = one comparison, one addition, one assignment, etc.
```

### For Different Input Sizes

| n | O(log n) | O(n) | O(n log n) | O(n²) | O(n³) |
|---|---|---|---|---|---|
| 10 | 3 ops ✅ | 10 ops ✅ | ~33 ops ✅ | 100 ops ✅ | 1,000 ✅ |
| 1,000 | ~10 ✅ | 1,000 ✅ | ~10,000 ✅ | 1,000,000 ✅ | 10⁹ ❌ |
| 10⁵ | ~17 ✅ | 10⁵ ✅ | ~3×10⁶ ✅ | 10¹⁰ ❌ | ❌ |
| 10⁹ | ~30 ✅ | 10⁹ ❌ | ❌ | ❌ | ❌ |

### Practical Rules

```
n = 10⁵  →  use O(n log n) or better  (avoid O(n²))
n = 10³  →  O(n²) is fine
n = 10⁹  →  only O(log n) or O(1) survives
```

### How to Calculate Complexity of Your Code

**Rule:** Total complexity = maximum of all independent sections.

```cpp
print("hello");          // O(1)
int a = 10;              // O(1)
int b = 20;              // O(1)
return a + b;            // O(1)
// Total: O(1)  ← max of all four O(1) sections
```

```cpp
for (i=0; i<100; i++)        // O(1)  ← 100 is a constant, NOT input
    print("hello");

for (i=0; i<n; i++)          // O(n)  ← depends on input
    print("hello");

// Total: O(n)  ← max(O(1), O(n))
```

```cpp
for (i=0; i<n; i++)          // O(n)
    for (j=0; j<n; j++)      // O(n)
        print("hello");
// Total: O(n²)  ← nested loops multiply
```

```cpp
sort(arr);                    // O(n log n)
for (i=0; i<n; i++) ...      // O(n)
// Total: O(n log n)  ← sort dominates
```

### Simplification Rules

```
O(n - 1)   →  O(n)     ← drop constants
O(2n)      →  O(n)     ← drop coefficients
O(n + 100) →  O(n)     ← drop smaller terms
O(n² + n)  →  O(n²)   ← keep the dominant term
```

---

## 12. Master Revision Sheet

### Problem → Pattern Map

| Problem | Key Setup | Core Two Pointer Logic | TC | SC |
|---|---|---|---|---|
| Two Sum | Sort array, i=0, j=n-1 | Shrink based on sum vs target | O(n log n) | O(1) |
| Remove Duplicates | officer + cm both start at 0/1 | Write unique, skip repeated | O(n) | O(1) |
| Squares of Sorted | i=0, j=n-1, fill result from back | Compare both ends, take larger square | O(n) | O(n) |
| Merge Sorted Arrays | i=0 in a[], j=0 in b[] | Take smaller, advance its pointer | O(n+m) | O(n) |
| Three Sum | Sort, fix i, left=i+1, right=n-1 | Two Sum on remaining, skip dupes | O(n²) | O(1) |
| 3Sum Closest | Sort, fix i, two pointers | Track min abs(sum - target) | O(n²) | O(1) |
| Triplets < Sum | Sort, fix i, two pointers | Add (right-left) when valid | O(n²) | O(1) |
| Two Sum No Dupes | Sort, i=0, j=n-1 | Store pair, skip duplicates | O(n log n) | O(1) |
| Dutch National Flag | low=0, mid=0, high=n-1 | 3-zone invariant with swap | O(n) | O(1) |

---

### The Decision Flowchart

```
Start here:
─────────────────────────────────────────────────────────────────
Is the data an Array or Linked List?
  │
  ├─ NO  → Two Pointer probably won't apply.
  │
  └─ YES
       │
       ├─ Need to find pair/triplet summing to target?
       │     └─ YES → Sort + Two Pointer
       │               (if you need INDEX not VALUE → HashMap instead)
       │
       ├─ Need to rearrange/remove duplicates/merge in-place?
       │     └─ YES → Two Pointer (no extra space needed)
       │
       ├─ Need squares in sorted order?
       │     └─ YES → Two Pointer from both ends (compare largest squares)
       │
       ├─ 0s, 1s, 2s rearrange?
       │     └─ YES → Dutch National Flag (3-pointer variant)
       │
       └─ Detect cycle in Linked List?
             └─ YES → Fast + Slow Pointer (Floyd's algorithm)
```

---

### Common Mistakes to Avoid

```
❌  Forgetting to sort before applying two pointer on unsorted input
❌  Using two pointer to find index (original order lost after sort)
❌  Not skipping duplicates in 3Sum / Two Sum No Dupes
❌  Doing mid++ after swapping with high in Dutch National Flag
❌  Using i < n instead of i < j as the while condition (pointers cross!)
❌  Confusing SC: O(n) is bad when the problem says "no extra space"
```

---

### Quick Complexity Cheat Sheet

```
Two Sum              →  O(n log n) time,  O(1) space
Remove Duplicates    →  O(n) time,        O(1) space
Squares of Sorted    →  O(n) time,        O(n) space
Merge Sorted         →  O(n) time,        O(n) space
3Sum                 →  O(n²) time,       O(1) space
3Sum Closest         →  O(n²) time,       O(1) space
Triplets < Sum       →  O(n²) time,       O(1) space
Dutch National Flag  →  O(n) time,        O(1) space
```

---

*All pseudocode is language-agnostic. Translate to C++ / Java / Python as needed.*
*Problems covered: Two Sum, Remove Duplicates, Squares of Sorted Array, Merge Sorted Arrays, 3Sum, 3Sum Closest, Triplets Smaller Than Sum, Two Sum No Duplicates, Dutch National Flag.*