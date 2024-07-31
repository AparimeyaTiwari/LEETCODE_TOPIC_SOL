#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp;
        while(fast != NULL && fast->next != NULL){
            tmp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        tmp->next = slow->next;
        delete slow;
        return head;
    }
};