/*
 Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/




class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> vec(3,-1);
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            vec[s[i]-'a'] = i;
            if(vec[0] != -1 && vec[1] != -1 && vec[2] != -1){
                cnt += *min_element(vec.begin(),vec.end())+1;
            }
        }
        return cnt;
    }
};


/*OPTIMAL USING MAP
TC->O(N)
SC->O(1)
map<char,int> mp = {{'a',-1},{'b',-1},{'c',-1}};
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            mp[s[i]] = i;
            if(mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1){
                if(mp['a']<mp['b'] && mp['a']<mp['c']){
                    cnt += mp['a']+1;
                }
                else if(mp['b']<mp['a'] && mp['b']<mp['c']){
                    cnt += mp['b']+1;
                }
                else{
                    cnt += mp['c']+1;
                }
            }
        }
        return cnt;
        */

/*BRUTE FORCE
TC->O(N^2)
SC->O(1)
        int cnt = 0;
        vector<int> op(3,0);
        for(int i = 0;i<s.size();i++){
            op[0] = 0;
            op[1] = 0;
            op[2] = 0;
            for(int j = i;j<s.size();j++){
                op[s[j]-'a'] ++;
                if(op[0]>=1 && op[1]>=1 && op[2]>=1){
                    cnt += s.size()-j;
                    break;
                }
            }
        }
        return cnt;
        */

 /*MY INVALID ATTEMPT
        vector<int> op(3,0);
        int l = 0, r = 0;
        int cnt = 0;
        while(true){ //finding mininum intial window size where condition is satifised
            op[s[r]-'a']++;
            if(op[0]>=1 && op[1]>=1 && op[2]>=1){
                break;
            }
            r ++;
        }
        cnt += 1 +(s.size()-(r-l+1));
        cout<<l<<" "<<r<<endl;
        while(r<s.size()-1 && r-l+1>=3){
            op[s[l]-'a'] --;
            l ++;
            while((op[0]<1 || op[1]<1 || op[2]<1)&& r<s.size()-1){
                r ++;
                op[s[r]-'a']++;
            }
            cout<<l<<" "<<r<<endl;
            if(op[0]>=1 && op[1]>=1 && op[2]>=1){
                cnt += 1 +(s.size()-r-1);
            }
            cout<<cnt<<endl;
        }
        return cnt;
        */
