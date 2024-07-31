/*
 Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

 In other words, return true if one of s1's permutations is the substring of s2.

  

 Example 1:

 Input: s1 = "ab", s2 = "eidbaooo"
 Output: true
 Explanation: s2 contains one permutation of s1 ("ba").
 Example 2:

 Input: s1 = "ab", s2 = "eidboaoo"
 Output: false
  

 Constraints:

 1 <= s1.length, s2.length <= 104
 s1 and s2 consist of lowercase English letters.

 */




class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> freq1(26,0); //vector for storing count of letters in s1
        vector<int> freq2(26,0); //"                                    " s2
        int matches = 0; //variable to store no of matches
        int n = s1.size();
        int m = s2.size(); //intial fill up
        int ind = 0;
        for(int i = 0;i<n;i++){
            freq1[s1[i]-'a'] ++;
            freq2[s2[i]-'a'] ++;
        }
        for(int i = 0;i<26;i++){ //traversal of whole arrays
            if(freq1[i] == freq2[i]) matches ++;
        }
        for(int j = n;j<m;j++){
            if(matches == 26) return true;
            ind = s2[j-n]-'a';
            freq2[ind] --;
            if(freq2[ind] == freq1[ind]) matches ++;
            else if(freq2[ind]+1 == freq1[ind]) matches --;
            ind = s2[j]-'a';
            freq2[ind] ++;
            if(freq2[ind] == freq1[ind]) matches ++;
            else if(freq1[ind]+1== freq2[ind]) matches --;
        }
        return(matches == 26);
        

    }
};



/*
        if(s1.size()>s2.size()) return false;
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        int n = s1.size();
        int m = s2.size();
        for(int i = 0;i<n;i++){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1 == f2) return true;
        for(int i = n;i<m;i++){
            f2[s2[i-n]-'a'] --;
            f2[s2[i]-'a'] ++;
            if(f1 == f2) return true;
        }
        return false;
        */
/*
        if(s2.size()<s1.size()){
            return false;
        }
        map<int,int> freq1;
        map<int,int> freq2;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            freq1[s1[i]] ++;
            freq2[s2[i]] ++;
        }
        if(freq1 == freq2) return true;
        for(int j = n;j<s2.size();j++){
            freq2[s2[j-n]] --;
            freq2[s2[j]] ++;
            if(freq2[s2[j-n]] == 0){
                freq2.erase(freq2.find(s2[j-n]));
            }
            if(freq1 == freq2) return true;
        }
        return false;
        */
