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
        ListNode *h1 = list1;
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *prev = NULL;
        
        if(list1 == NULL)
           return list2;
        if(list2 == NULL)
            return list1;
        
        while(ptr2->next!= NULL && ptr2->next->val <= ptr1->val) {
            ptr2 = ptr2->next;
        }
        if(ptr2->val <= ptr1->val) {
            ListNode *nxt = ptr2->next;
            ptr2->next = ptr1;
            prev = ptr2;
            list1 = list2;
            ptr2 = nxt;
        }
        // cout<<ptr2->val<<endl;
        while(ptr1!=NULL && ptr2!=NULL) {
            if(ptr2->val > ptr1->val) {
                prev = ptr1;
                ptr1 = ptr1->next;
                // cout<<prev->val<<" "<<ptr1->val<<endl;
            }
            else {
                ListNode *nxt = ptr2->next;
                // cout<<ptr2->val<<endl;
                prev->next = ptr2;
                prev = ptr2;
                ptr2->next = ptr1;
                ptr2 = nxt;
            }
        }
        
        if(ptr1 ==  NULL)
            prev->next = ptr2;
        
        return list1;
        
    }
};