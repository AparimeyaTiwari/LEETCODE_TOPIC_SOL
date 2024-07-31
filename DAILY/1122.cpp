/*class Solution {
 public:
 vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
 vector<int> result;
 int i = 0;
 for(i = 0;i<arr2.size();i++)
 {
 int j = 0;
 while(j<arr1.size())
 {
 if(arr1[j] == arr2[i])
 {
 result.push_back(arr1[j]);
 arr1[j] = -1;
 }
 j ++;
 }
 }
 int intialsize = result.size();
 for(i=0;i<arr1.size();i++)
 {
 if(arr1[i] != -1)
 {
 result.push_back(arr1[i]);
 }
 }
 sort(result.begin()+intialsize,result.end());
 return result;
 
 }
 };
 */
/* APPROACH 2
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       unordered_map<int,int> mp;
       vector<int> result, remain;
       int i,j;
       for(i = 0;i<arr2.size();i++)
       {
        mp[arr2[i]] = 0;
       }
       for(i = 0;i<arr1.size();i++)
       {
        if(mp.find(arr1[i]) != mp.end())
        {
            mp[arr1[i]] ++;
        }
        else
        {
            remain.push_back(arr1[i]);
        }
       }
       sort(remain.begin(),remain.end());
       for(i = 0;i<arr2.size();i++)
       {
        for(j = 0;j<mp[arr2[i]];j++)
        {
            result.push_back(arr2[i]);
            
        }
       }
       for(i = 0;i<remain.size();i++)
       {
        result.push_back(remain[i]);
       }
       return result;
    }

*/
/* class Solution {
 public:
     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         int maxEle = *max_element(arr1.begin(),arr1.end());
         vector<int> cnt(maxEle+1);
         vector<int> result;
         for(int num:arr1)
         {
             cnt[num] ++;
         }
         
         for(int num:arr2)
         {
             while(cnt[num]>0)
             {
                 result.push_back(num);
                 cnt[num]--;
             }
         }
         for(int i = 0;i<=maxEle;i++)
         {
             while(cnt[i]>0)
             {
                 result.push_back(i);
                 cnt[i]--;
             }
         }


         return result;

     }
 };*/
