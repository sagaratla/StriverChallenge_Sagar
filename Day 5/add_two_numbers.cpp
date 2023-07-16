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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        
        if(l1 == nullptr) {
            return l2;
        }
        
        if(l2 == nullptr) {
            return l1;
        }
        
        ListNode *trav1 = l1, *trav2 = l2;
        
        ListNode* newHead = nullptr;
        ListNode* currPtr = nullptr;
        int carry = 0;
        
        while(trav1 != nullptr && trav2 != nullptr) {
            int temp = carry + trav1->val + trav2 ->val;
            // 1 + 5 + 4 = 10, carry will be 1 & curr point will be 0
            if(temp > 9) {
                carry = 1;
                temp = temp % 10;
            } else {
                carry = 0;
            }
            
            if(newHead == nullptr) {
                newHead = new ListNode(temp);
                currPtr = newHead;
            } else {
                currPtr->next = new ListNode(temp, nullptr);
                currPtr = currPtr->next;
            }
            
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        
        while(trav1 != nullptr) {
            int temp = carry + trav1->val;
            
            if(temp > 9) {
                carry = 1;
                temp = temp % 10;
            } else {
                carry = 0;
            }
            
            currPtr->next = new ListNode(temp, nullptr);
            currPtr = currPtr->next;
            
            trav1 = trav1->next;
        }
        
        while(trav2 != nullptr) {
            int temp = carry + trav2->val;
            
            if(temp > 9) {
                carry = 1;
                temp = temp % 10;
            } else {
                carry = 0;
            }
            
            currPtr->next = new ListNode(temp, nullptr);
            currPtr = currPtr->next;
            
            trav2 = trav2->next;
        }
        
        if(carry == 1) {
            currPtr->next = new ListNode(1, nullptr);
        }
        
        return newHead;
    }
};