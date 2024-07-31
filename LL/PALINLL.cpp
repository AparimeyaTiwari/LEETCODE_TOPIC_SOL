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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //finding middle element
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = NULL;
        ListNode* temp;//to store node after slow
        while(slow != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        while(prev != NULL){
            if(prev->val != head->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};




/*stack<int> st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->val != st.top()){
                return false;
            }
            else{
                st.pop();
                temp = temp->next;
            }
        }
        return true;


/*
        //base case
        if(head->next->next == NULL || head->next == NULL){
            if(head->next == NULL){
                return true;
            }
            if(head->val == head->next->val){
                return true;
            }
            else{
                return false;
            }
        }
        //counting number of elements in ll
        int cnt = 0;
        ListNode* temp = head;
        while(temp->next != NULL){
            cnt ++;
            temp = temp->next;
        }
        temp = head;
        ListNode* prev;
        ListNode* fast = head;
        //getting to middle of linked list
        while( fast != NULL && fast->next != NULL){
            prev = temp;
            temp = temp->next;
            fast == fast->next->next;
        }
        if(cnt % 2 == 0){
            if(temp->val != temp->next->val){
                return false;
            }
            else{
                prev = temp->next->next;
                return isPalindrome(head);
            }
        }
        else{
            prev = temp->next;
            return isPalindrome(head);
        }
        */