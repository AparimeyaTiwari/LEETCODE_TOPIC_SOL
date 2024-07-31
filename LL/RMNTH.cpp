#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head); //ADDING DUMMY NODE TO THE START
        ListNode* L = dummy;//SET LEFT PTR TO DUMMY
        ListNode* R = head; //SET RIGHT PTR TO HEAD
        for(int i = 0;i<n;i++){
            R = R->next;
        }
        while(R != NULL){
            L = L->next;
            R = R->next;
        }
        L->next = L->next->next;
        return dummy->next;
        }
};

/*APPROACH 1:OPTIMIAL */
/*
 1--->2--->3--->4--->5-->NULL
 n = 3
 HERE WE MUST DELETE NODE 3
 1--->2--->3--->4--->5-->NULL
 L              R
      L              R
           L              R
 
 LEFT IS AT NODE TO DELETE
 BUT WE WANT NODE BEHIND IT
 HENCE DUMMY NODE
 0---> 1--->2--->3--->4--->5-->NULL
            L         LNN        R
 L ->NEXT = LNN
 return dummy->next
 since we don't want to return dummy
 */


/*APPROACH 2
 BRUTE FORCE:
 ->The position to delete would be len of LL(including NULL) - n
 ->since when n = 1 we talk about the last element
 ->find postion by traversing once
 ->set variable to 1
 ->move ahead till we reach position, maintain previous pointer
 ->delete
 
 TC = O(2N) = O(N)
 SC = 0(1)
 
 //if only one element exist
 if(head->next == NULL){
     head = head->next;
     return head;
 }
 int sz = 1;
 ListNode* temp = head;
 ListNode* prev = NULL;
 while(temp != NULL){
     temp = temp->next;
     sz ++;
 }
 int pos = sz-n;
 if(pos == 1){
     head = head->next;
     return head;
 }
 sz = 1;
 temp = head;
 prev = NULL;
 while(sz != pos){
     prev = temp;
     temp = temp->next;
     sz ++;
 }
 prev->next = temp->next;
 return head;
*/
