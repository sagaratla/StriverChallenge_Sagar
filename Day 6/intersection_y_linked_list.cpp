/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA, *tempB = headB;
        while(true) {
            // cout<<tempA->val<<endl;
            // cout<<tempB->val<<endl;
            if(tempA == tempB) {
                return tempA;
            }

            tempA = tempA->next;
            tempB = tempB->next;
            
            if(tempA == nullptr && tempB == nullptr) {
                return nullptr;
            }
            
            if(tempA == nullptr) {
                tempA = headB;
            }
            
            if(tempB == nullptr) {
                tempB = headA;
            }
        }
        return nullptr;
    }
};