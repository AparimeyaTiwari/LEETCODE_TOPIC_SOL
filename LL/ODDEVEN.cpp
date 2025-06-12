#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* first = head->next;
        while(odd->next != NULL && odd->next->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        if(even != NULL){
            even->next = NULL;
        }
        odd->next = first;
        return head;
    }
};