#include <iostream>
using namespace std;
/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;
        while(fast != NULL && fast->next != NULL){
            if(fast == slow and cnt!=0){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
            cnt ++;
        }
        return false;
    }
};

/*
unordered_set<ListNode* > LL;
        while(head != NULL){
            if(LL.find(head) != LL.end()){
                return true;  
            }
            LL.insert(head);
            head = head->next; 
        }
        return false;
*/
