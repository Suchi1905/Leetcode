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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* kthNode=findkthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode!=NULL)
                prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            ListNode* newHead=reverse(temp);
            if(temp==head)
            head=kthNode;
            else
            prevNode->next=kthNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
    ListNode* findkthNode(ListNode* temp, int k) {
    while (temp != NULL && k > 1) {
        temp = temp->next;
        k--;
    }
    return temp;
    }
    ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
};