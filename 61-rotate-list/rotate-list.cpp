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
        int len=1;
        ListNode* tail=head;
        if(head==NULL || k==0 ||head->next==NULL) return head;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
            k=k%len;
            tail->next=head;
            ListNode* newLastNode=findNthNode(head,len-k-1);
            head=newLastNode->next;
            newLastNode->next=NULL;
            return head;
    }
    ListNode* findNthNode(ListNode* head,int cnt){
        ListNode* temp=head;
        while(cnt!=0){
            temp=temp->next;
            cnt--;
        }
        return temp;
    }
};