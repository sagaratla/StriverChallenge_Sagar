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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while(fast!= nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        
        // reverse the other half
        ListNode *second_head = slow;
        ListNode *next = slow;
        prev = nullptr;
        while(slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        second_head = prev;
        
//         ListNode *curr = second_head;
//         while(curr != nullptr) {
//             cout<<curr->val<< "->";
//             curr = curr->next;
//         }
//         cout<<endl;
        
//         curr = head;
        
        ListNode* trav2 = second_head;
        ListNode* trav1 = head;
        
        while(trav1 != nullptr) {
            if(trav1->val != trav2->val) {
                return false;
            }
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        
        return true;
    }
};