#include <iostream>
#include <string>
#include <vector>
#include <set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s1(nums.begin(),nums.end());
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            if(s1.find(curr->val) != s1.end()){
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
                prev = curr;
                curr = curr->next;

            }
        }
        return head;
    }
        
};


/*
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i = 0;i<nums.size();i++){
            int s = nums[i];
            curr = head;
            prev = NULL;
            while(curr != NULL){
                if(curr->val==s){
                    if(curr == head){
                        head = head->next;
                        curr = head;xx
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
        }
        return head;
        */