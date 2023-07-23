/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

// ---- next
// |||| child

Node* mergeTwoLists(Node* list1, Node* list2) {
	if(list1 == nullptr && list2 == nullptr) {
		return nullptr;
	}
	
	if(list1 == nullptr) {
		return list2;
	}
	
	if(list2 == nullptr) {
		return list1;
	}
	
	Node *temp_ptr = new Node(-9999);
	Node *dummy = temp_ptr;
	
	Node* ptr1 = list1, *ptr2 = list2;
	while(ptr1 != nullptr && ptr2 != nullptr) {
		// cout<<temp_ptr->data<<"->";
		if(ptr1->data <= ptr2->data) {
			temp_ptr->child = ptr1;
			ptr1 = ptr1->child;
		} else {
			temp_ptr->child = ptr2;
			ptr2 = ptr2->child;
		}
		temp_ptr = temp_ptr->child;
	}
	
	while(ptr1 != nullptr) {
		// cout<<temp_ptr->data<<"->";
		temp_ptr->child = ptr1;
		ptr1 = ptr1->child;
		temp_ptr = temp_ptr->child;
	}
	
	while(ptr2 != nullptr) {
		// cout<<temp_ptr->data<<"->";
		temp_ptr->child = ptr2;
		ptr2 = ptr2->child;
		temp_ptr = temp_ptr->child;
	}
	list1->next = nullptr;
	list2->next = nullptr;
	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head->next == nullptr) {
		return head;
	}
	Node* head2 = flattenLinkedList(head->next);
	return mergeTwoLists(head, head2);
}
