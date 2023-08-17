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
      ListNode* reverse(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
         ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode*node = head->next;
        while (cur != NULL) {
            cur->next = pre;
            pre = cur;
            cur = node;
            if (node != nullptr) node = node->next;
        }
        return pre;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
      if(l1==NULL and l2==NULL)return NULL;
     else if(l1==NULL)return l2;
     else if(l2==NULL)return l1;
     int sum = l1->val+l2->val;
     ListNode*ans = new ListNode(sum%10);
     ans->next = add(l1->next,l2->next);
     if(sum>=10) ans->next = add(ans->next,new ListNode(1));
     return ans;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* head1 = new ListNode(head->val);
        ListNode* node = head1;
        ListNode* temp = head->next;
        while (temp) {
            ListNode* a = new ListNode(temp->val);
            node->next = a;
            node = node->next;
            temp = temp->next;
        }
        ListNode* a = reverse(head);
        ListNode* b = reverse(head1);
        ListNode* res = add(a, b);
        ListNode* ans = reverse(res);
        return ans;
    }
};