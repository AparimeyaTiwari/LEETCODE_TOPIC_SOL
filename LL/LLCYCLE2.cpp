/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*unordered_set<ListNode*> cycle;
        while(head != NULL){
            if(cycle.find(head) != cycle.end()){
                return head;
            }
            else{
                cycle.insert(head);
            }
            head = head->next;
        }
        return NULL;
    }
};
*/