#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0,head);//present just before head. Helps reduce edge cases
        ListNode* curr = head; //prev points to element before curr. Will manipulate this for deletion
        ListNode* prev = dummy; //curr points to curr element
        while(curr != NULL){
            ListNode* nxt = curr->next; //points directly to the next element
            if(curr->val == val){
                prev->next = nxt;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};


/*
        //Case when we have empty ll
        if(head == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev;
        //deleting in other cases
        while(curr != NULL){
            if(curr->val == val){
                if(head->val == val){
                    curr = head->next;
                    head->next = NULL;
                    head = curr;
                }
                else if(curr->next == NULL){
                    curr = NULL;
                    prev->next = NULL;
                }
                else{
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    */