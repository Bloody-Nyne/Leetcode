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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos = 1;
        ListNode *prev = nullptr, *cur = head, *prev_end = nullptr, *nxt = cur->next , *st = cur;
        
        if(left>=right) return head;
        
        while(pos<=right) {
            if(pos<left) {
                prev_end = cur;
                prev = cur;
                cur = nxt;
                st = cur;
                nxt = cur->next;
            }
            else if(pos>=left && pos<=right){
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            pos++;
        }
        
        if(prev_end) {
            prev_end->next = prev;
            st->next = cur;
        }
        else {
            head = prev;
            st->next = cur;
        }
        
        return head;
        
    }
};