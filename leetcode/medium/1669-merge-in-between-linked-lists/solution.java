/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode beforeA = list1;
        for (int i=0; i<a-1; i++){
            beforeA = beforeA.next;
        }

        ListNode afterB = beforeA;
        for (int i=0; i<=b-a+1; i++){
            afterB = afterB.next;
        }

        beforeA.next = list2;
        ListNode last2 = list2;
        while (last2.next != null){
            last2 = last2.next;
        }
        last2.next = afterB;
        return list1;
    }
}