#include <iostream>
#include <vector>
using namespace std;

 Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* newHead;
        newHead = head;
        if(head != NULL){
            newHead = reverseList(head->next);
            head->next->next = newHead;
        }
        head->next = NULL;
        return newHead;
        
    }
};


/*ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
*/

/* vector<int> rev;
        ListNode* temp = head;
        while(temp != NULL){
            rev.push_back(temp->val);
            temp = temp->next;
        } //0(N)
        temp = head;
        int j = rev.size()-1;
        while(j>=0){//0(N)
            temp->val = rev[j];
            temp = temp->next;
            j --;
        }
        return head;
*/