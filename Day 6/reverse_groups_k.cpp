/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *pre = dummy, *curr = dummy, *next = dummy;
        int n = 0;
        while(curr->next != nullptr) {
            curr = curr->next;
            n++;
        }
        
        // do in groups of k
        while(n >= k) {
            curr = pre->next;
            next = curr->next;
            
            // perform those operations k-1 times since 3 nodes means 2 links
            for(int i=1;i<k;i++) {
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            n-=k;
        }
        
        return dummy->next;
    }
};