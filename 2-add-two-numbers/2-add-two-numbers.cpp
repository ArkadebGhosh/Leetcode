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
        ListNode *head = NULL;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p3 = head;
        
        int carry = 0;
        
        while(p1!=NULL || p2!=NULL) {
            int s1 = p1!=NULL?(p1->val): 0;
            int s2 = p2!=NULL?(p2->val): 0;
            int sum = (s1+s2+carry)%10;
            carry = (s1+s2+carry)/10;
            ListNode* newnode = new ListNode(sum);
            if(p3 == NULL) {
                head = newnode;
                p3 = head;
            }
            else {
                p3->next = new ListNode(sum);
                p3 = p3->next;
            }
            p1= p1==NULL?p1: p1->next;
            p2= p2==NULL?p2: p2->next;
        }
        if(carry!=0)
            p3->next = new ListNode(carry);
        return head;
    }
};