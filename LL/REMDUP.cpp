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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        unordered_set<int> s;
        while(curr != NULL){
            if(s.find(curr->val) != s.end()){
                if(prev == NULL){
                    head = head->next;
                    curr = head;
                }
                else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else{
                s.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
            
        }
        return head;
    }
};