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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        
        if(list1 == nullptr) {
            return list2;
        }
        
        if(list2 == nullptr) {
            return list1;
        }
        
        ListNode *temp_ptr = new ListNode(-9999);
        ListNode *dummy = temp_ptr;
        
        ListNode* ptr1 = list1, *ptr2 = list2;
        while(ptr1 != nullptr && ptr2 != nullptr) {
            // cout<<temp_ptr->val<<"->";
            if(ptr1->val <= ptr2->val) {
                temp_ptr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                temp_ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            temp_ptr = temp_ptr->next;
        }
        
        while(ptr1 != nullptr) {
            // cout<<temp_ptr->val<<"->";
            temp_ptr->next = ptr1;
            ptr1 = ptr1->next;
            temp_ptr = temp_ptr->next;
        }
        
        while(ptr2 != nullptr) {
            // cout<<temp_ptr->val<<"->";
            temp_ptr->next = ptr2;
            ptr2 = ptr2->next;
            temp_ptr = temp_ptr->next;
        }
        return dummy->next;
    }
};