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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            temp = temp->next;
            n++;
        }
        
        // make sure the k is less than n
        k = k%n;
        if(k==0) {
            return head;
        }
        
        temp = head;
        int count = 0;
        while(count < (n-k-1)) {
            temp = temp->next;
            count++;
        }
        ListNode* old_end = temp;
        ListNode* new_head = temp->next;
        temp = new_head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        // temp is currently at the end of the list
        old_end->next = nullptr;
        temp->next = head;
        head = new_head;
        
        return head;
    }
};