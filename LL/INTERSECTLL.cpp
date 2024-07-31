/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int s1 = 0;
        int s2 = 0;
        while(tempA != NULL){
            s1 ++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            s2 ++;
            tempB = tempB->next;
        }
        int diff = abs(s1-s2);
        tempA = headA;
        tempB = headB;
        if(s2>s1){
            while(diff != 0){
                tempB = tempB->next;
                diff --;
            }
        }
        else{
            while(diff != 0){
                tempA = tempA->next;
                diff --;
            }
        }
        while(tempA != NULL && tempB != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};



/*ListNode* tempA = headA;
        ListNode* tempB = headB;
        unordered_set<ListNode* > nodes;
        while(tempA != NULL){
            nodes.insert(tempA);
            tempA = tempA->next;
        }
        while(tempB != NULL){
            if(nodes.find(tempB) != nodes.end()){
                return tempB;
            }
            tempB = tempB->next;
        }
        return NULL;
        */
