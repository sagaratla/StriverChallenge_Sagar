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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = dummy, *fast = dummy;
        
        int count = 0;
        while(count < n) {
            fast = fast -> next;
            count++;
        }
        
        // fast is at the last position
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // then we remove the slow->next
        ListNode *store = slow -> next;
        slow -> next = slow -> next -> next;
        delete(store);
        
        return dummy->next;
    }
};