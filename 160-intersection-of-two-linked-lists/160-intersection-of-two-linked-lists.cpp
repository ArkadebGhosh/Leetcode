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
        int c1 = 0, c2 = 0;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while(ptr1 != NULL) {
            ptr1=ptr1->next;
            ++c1;
        }
        while(ptr2 != NULL) {
            ptr2=ptr2->next;
            ++c2;
        }
        if(c1 > c2) {
            ptr1 = headA;
            ptr2 = headB;
        }
        else {
            ptr1 = headB;
            ptr2 = headA;
        }
        
        int ahead = abs(c2-c1);
        cout<<ahead<<endl;
        while(ahead--)
            ptr1 = ptr1->next;
        while(ptr1!=ptr2) {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
    }
};