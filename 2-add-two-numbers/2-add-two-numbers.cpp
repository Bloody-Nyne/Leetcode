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
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void insertattail(ListNode* &head, ListNode* &tail, int value){
        ListNode* temp=new ListNode(value);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    ListNode* add(ListNode* first,ListNode* second){
        int carry=0;
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        
        while(first || second || carry!=0){
            int val1=0;
            if(first){
                val1=first->val;
            }
            int val2=0;
            if(second){
                val2=second->val;
            }
            int sum=carry + val1 + val2;
            int digit=sum%10;
            
            insertattail(ansHead,ansTail,digit);
            
            carry=sum/10;
            if(first)
                first=first->next;
            if(second)
                second=second->next;
        }
        return ansHead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return NULL;
        if(l2==NULL) return NULL;
     //   ListNode* head1=reverse(l1);
     //   ListNode* head2=reverse(l2);
        
        ListNode* ans=add(l1,l2);
        
       // ans=reverse(ans);
        
        return ans;
    }
};