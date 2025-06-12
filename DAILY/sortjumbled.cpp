/*
 You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

 The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

 You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

 Notes:

 Elements with the same mapped values should appear in the same relative order as in the input.
 The elements of nums should only be sorted based on their mapped values and not be replaced by them.
  

 Example 1:

 Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
 Output: [338,38,991]
 Explanation:
 Map the number 991 as follows:
 1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
 2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
 Therefore, the mapped value of 991 is 669.
 338 maps to 007, or 7 after removing the leading zeros.
 38 maps to 07, which is also 7 after removing leading zeros.
 Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
 Thus, the sorted array is [338,38,991].
 Example 2:

 Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
 Output: [123,456,789]
 Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
  

 Constraints:

 mapping.length == 10
 0 <= mapping[i] <= 9
 All the values of mapping[i] are unique.
 1 <= nums.length <= 3 * 104
 0 <= nums[i] < 109
 */


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> storepair;//store newnumber and index
        for(int i = 0;i<nums.size();i++){
            string temp = to_string(nums[i]);//converts each number to string
            string newnumber = ""; //newstring where we add
            for(int j = 0;j<temp.size();j++){
                newnumber += to_string(mapping[temp[j]-'0']); //creating newstring
            }
            int nn = stoi(newnumber);
            storepair.push_back({nn,i});//storing newnumber(int) and index
        }
        sort(storepair.begin(),storepair.end());
        vector<int> op;
        for(auto &sp:storepair){
            op.push_back(nums[sp.second]);
        }
        return op;
 
    }
};







/*
//returning converted value
    int newnumber(vector<int>& mapping,int x){
        //if the number is already 0, we must map it to mapping[0]
        if(x == 0){
            return mapping[0];
        }
        //actual conversion of number
        int nn = 0;
        int cnt = 0;
        while(x != 0){
            nn += mapping[x%10]*pow(10,cnt); //adding last number * 10 * cnt->it's place(1's 10's)
            x /= 10;
            cnt ++;
        }
        return nn;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multimap<int,int> mp;//since two different numbers can have the same value
        int i;
        for(auto &n:nums){
            i = newnumber(mapping,n); //retreiving new number
            mp.insert(make_pair(i,n)); // mapping it to old number
            n = i;
        }
        //sorted map with keys as new number->old number
        int j = 0;
        //adding to nums
        for(auto &m:mp){
            cout<<m.first<<" "<<m.second<<endl;
            nums[j] = m.second;
            j ++;
        }
        return nums;
    }
*/
