/*
 You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
 */





class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /* OPTIMAL APPROACH */
        /*
        LOGIC->
        I)Tranverse through nums
        II)Ptr p->positive indexes Ptr n->negative indexes
        III)If negative number add to negative index else to positive index of op
        IV)Increment p by 2 and Increment n by 2 after insertion
        */
        vector<int> op(nums.size(),0);
        int p = 0, n=1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                op[p] = nums[i];
                p += 2;
            }
            else{
                op[n] = nums[i];
                n += 2;
            }
        }
        return op;
    }
};





/*APPROACH 2*/
/*
LOGIC->
SINCE NUMS[0]->POS AND ALTERNATE ARRANGEMENT
    I)EVEN INDEXES->POS
    II)ODD INDEXES->EVEN
I)SET PTR P->POS NUMBERS
II)SET PTR N->NEG NUMBERS
III)IF EVEN INDEX FIND FIRST POS NUMBER ->ADD
IV)IF ODD INDEX FIND FIRST NEGATIVE NUMBER ->ADD

        vector<int> op;
        int p = 0, n = 0;
        for(int i = 0;i<nums.size();i++){
            if(i%2 == 0){
                while(nums[p]<0){
                    p ++;
                }
                op.push_back(nums[p]);
                p++;
            }
            else{
                while(nums[n]>0){
                    n ++;
                }
                op.push_back(nums[n]);
                n++;
            }
        }
        return op;
        */
/*BRUTE FORCE*/
/*LOGIC->
I)STORE ALL POSITVE NUMBERS IN POS ARR
II)STORE ALL NEGATIVE NUMBERS IN NEG ARR
III)ADD ONE FROM POS THEN ONE FROM NEG TO OUTPUT
        vector<int> pos,neg,op;
        for(auto &n:nums){
            if(n>0){
                pos.push_back(n);
            }
            else{
                neg.push_back(n);
            }
        }
        for(int i = 0;i<pos.size();i++){
            op.push_back(pos[i]);
            op.push_back(neg[i]);
        }
        return op;
        */
