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
    void reorderList(ListNode* head) {
        ListNode *mid = middle(head);
        // cout<<mid->val<<endl;
        ListNode *rev = reverse(mid);
        reorder(head, rev);
    }
    
    ListNode *middle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast!=NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL)
                fast=fast->next;
        }
        return slow;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *prev= NULL;
        ListNode *curr = head;
        while(curr!=NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    void reorder(ListNode *head1, ListNode *head2) {
        ListNode *ptr1 = head1, *ptr2 = head2;
        while(ptr2!=NULL) {
            ListNode *temp = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr2;
            ptr2 = temp;
        }
        ptr1->next = NULL;
    }
};