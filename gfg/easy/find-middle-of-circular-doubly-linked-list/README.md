# Find Middle of Circular Doubly Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the head of a  **circular** doubly linked list of  **odd size**, the task is to print the middle element.
The tail of a circular doubly linked list is connected to head via its next pointer, and the previous pointer of head is connected to the tail.

 **Examples:** 

```
Input:
LinkedList: 1<-->2<-->3
(The first and the last node is connected,
i.e 3 <--> 1)
Output: 2
Explanation: The middle element is 2.
```

```
Input: head: 1
Output: 1
Explanation: The middle element is 1.
```

 **Constraints:** 
1 ≤ list.size, node->data ≤ 103

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T04:47:02.011Z  

```java
class Solution {
    public static int findMiddle(Node head) {
        // code here
        Node slow = head;
        Node fast = head;
        
        while (fast.next != head){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow.data;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-middle-of-circular-doubly-linked-list/1)