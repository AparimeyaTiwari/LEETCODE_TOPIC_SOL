class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0; //left to shrink window and right to expand
        int count = 0; //count of number of zeros
        int max_len = 0; //maximum lenght of window
        for(right = 0;right<nums.size();right++){
            if(nums[right]==0) count ++; //counting zeros, if zero encountered count incremented by 1
            while(count>k){ //case when count>k, we move left till 1 0 removed
                if(nums[left]==0) count --;
                left++;
            }
            max_len = max(max_len,right-left+1); //find maximum length thera after
            //continute incrementing right
        }
        return max_len;
        

    }
};

















/*int i = 0,j=0,max_len=0,cnt=0,curr_len=0;

        for(i=0;i<nums.size();i++){
            cnt = 0;//counting 0's
            j = i;
            while(cnt<k and j<nums.size()){
                if(nums[j]==0){
                    cnt ++;
                    cout<<"cnt: "<<cnt<<endl;
                }
                j++;
            }
            cout<<"j: "<<j<<endl;
            cout<<"i: "<<i<<endl;
            curr_len = j-i;
            cout<<"len: "<<curr_len<<endl;
            if(curr_len>max_len){
                max_len = curr_len;
            }
            cout<<"max_len: "<<max_len<<endl;
        }
        return max_len;
        */
/*int count = 0;//count number of 0's encountered
        int i = 0;
        int j = 0;
        int max_len = 0,curr_len = 0;
        while(count<k && j<nums.size()){
            if(nums[j]==0) count ++;
            j++;
        }
        cout<<"J: "<<j<<endl;
        max_len = j;
        for(i = j;i<nums.size();i++){
            if(nums[i-j] == 0){
                count --;
            }
            if(nums[i]== 0){
                count ++;
            }
            if(count>k){
                continue;
            }
            else{
                if(nums[i+1] == 1){
                    curr_len = i+1+i-j+1;
                    if(curr_len >max_len){
                        max_len = curr_len;
                    }
                }
            }
        }
        return max_len;
    */

