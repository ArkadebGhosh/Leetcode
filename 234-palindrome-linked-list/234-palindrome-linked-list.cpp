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
        if(head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
        }
        
        ListNode *ptr2 = reverse(slow);
        // cout<<ptr2->val<<endl;
        ListNode *ptr1 = head;
        while(ptr2!=NULL) {
            if(ptr1->val != ptr2->val)
                return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
};