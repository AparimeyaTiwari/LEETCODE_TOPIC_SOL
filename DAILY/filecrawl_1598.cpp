/*
 The Leetcode file system keeps a log each time some user performs a change folder operation.

 The operations are described below:

 "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
 "./" : Remain in the same folder.
 "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
 You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

 The file system starts in the main folder, then the operations in logs are performed.

 Return the minimum number of operations needed to go back to the main folder after the change folder operations.

  

 Example 1:



 Input: logs = ["d1/","d2/","../","d21/","./"]
 Output: 2
 Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
 Example 2:



 Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
 Output: 3
 Example 3:

 Input: logs = ["d1/","../","../","../"]
 Output: 0
  

 Constraints:

 1 <= logs.length <= 103
 2 <= logs[i].length <= 10
 logs[i] contains lowercase English letters, digits, '.', and '/'.
 logs[i] follows the format described in the statement.
 Folder names consist of lowercase English letters and digits.
 */


class Solution {
public:
    int minOperations(vector<string>& logs) {
        /*APPROACH 2: STACK*/
        /*LOGIC->maintain a stack
               ->if we encounter "../" we must pop(if st not empty) This would mean going up a level
               ->if "./" ignore
               ->else add to stack
        O(N)->time complexity
        O(N)->space complexity
        */
        /*
        stack<string> st;
        string m = "../";
        string r = "./";
        for(auto &l:logs){
            if(l == m){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(l == r){
                continue;
            }
            else{
                st.push(l);
            }
        }
        return st.size();
        */
    }
};



/*APPRAOCH 1: COUNTER */
/*LOGIC:->maintain current directory depth
        ->if we encounter "../" cnt --(if already not 0)
        ->if "./" do nothing
        ->else just go down a level ++cnt;
  O(N)-> note: string cmp->O(N) but since length is fixed O(1)
  O(1)->space complexity
*/
/*
        int cnt = 0;
        string m = "../";
        string r = "./";
        for(auto &l:logs){
            if(l == m){
                cnt = max(0,cnt-1);
            }
            else if(l == r){
                continue;
            }
            else{
                cnt ++;
            }
        }
        return cnt;
        */
