class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /*
        TIME COMPLEXITY-> O(N) since r goes ahead each time-> each element encountered onces
        SPACE COMPLEXITY->O(1)
        LOGIC:
        You need to think about two things as far as any window is concerned. One is the starting point for the window. How do you detect that a new window of 1s has
        started? The next part is detecting the ending point for this window. How do you detect the ending point for an existing window? If you figure these two things out,
        you will be able to detect the windows of consecutive ones. All that remains afterward is to find the longest such window and return the size.
        1)WHEN 1 ENCOUNTERED-> CALCULATE LENGTH
        2)WHEN 0 ENCOUNTERED-> GO AHEAD TILL FIRST 1(L = R IN ORDER TO RESET THINGS)
        */

        if(nums.size()==1) return nums[0];
        int l = 0,r=0,max_len = 0;
        while(r<nums.size()){
            if(nums[r]==1){
                max_len = max(max_len,r-l+1); //ONLY HERE SINCE WE ARE EXPANDING
                r++;
            }
            else{
                while(r<nums.size() && nums[r]==0){
                    r++;
                    l = r; // TO RESET
                }
            }
        }
        return max_len;
    }
};

/*
        MY APPROACH 
        TIME COMPLEXITY-> O(N) since r goes ahead each time-> each element encountered onces
        SPACE COMPLEXITY->O(1)
        HERE-> 0 TO RESET

        if(nums.size()==1) return nums[0];
        int max_cnt = INT_MIN,cnt=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1) cnt++;
            else cnt = 0;
            max_cnt = max(max_cnt,cnt);
        }
        return max_cnt;

        */
