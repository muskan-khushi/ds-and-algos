# Cycle Length in Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the head of a linked list. A linked list contains a cycle if its last node is connected to a previous node. If the given list contains a cycle, return the length of the cycle. Otherwise, return 0.

 **Note:**  Internally, the driver code uses an integer  **x**  to represent the position (1-based indexing) of the node to which the last node is connected. If x = 0, it means last node points to null which indicating there is no loop.

 **Examples:** 

```
Input: 

Output: 4
Explanation: There exists a loop in the linked list 2 -> 3 -> 4 -> 5, the length of the loop is 4.

```

```
Input:

Output: 3
Explanation: There exists a loop in the linked list 19 -> 33 -> 10, the length of loop is 3.
```

```
Input:

Output: 0
Explanation: There is no loop.
```

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T05:36:39.444Z  

```java
/* Structure of Linked List Node
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}*/

class Solution {
    public int lengthOfLoop(Node head) {
        // code here
        Node slow = head;
        Node fast = head;
        
        while (fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) break;
        }
        
        if (fast == null || fast.next == null) return 0;
        
        Node entry = head;
        while (entry != slow){
            slow = slow.next;
            entry = entry.next;
        }
        
        int length = 1;
        
        Node curr = entry.next;
        while (curr != entry){
            curr = curr.next;
            length++;
        }
        return length;
    }
}
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-length-of-loop/1)