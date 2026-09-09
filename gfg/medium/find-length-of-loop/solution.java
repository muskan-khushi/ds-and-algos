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
        
        while (fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) break;
        }
        
        if (fast == null || fast.next == null) return 0;
        
        Node entry = head;
        while (slow != entry){
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