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