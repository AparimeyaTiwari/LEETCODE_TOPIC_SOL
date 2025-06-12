/*
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

 

Example 1:

Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
Example 2:

Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
Example 3:

Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
*/

/*
APPROACH 1]
-> Here, we simply must use two pointer to traverse both string
-> if the ith character of t is found in s then
    i += 1
    j += 1
->else we continue the search for the iths char of t in s
->if not found we end the loop and return (len(t)-i)


*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i,j;
        i = 0; //pointer for string t
        j = 0; //pointer for string s
        while(i<t.length() && j<s.length())
        {
            if(s[j] == t[i])
            {
                i ++;
            }
            j ++;
        }
        return (t.length()-i);
    }
};

int main(){
    Solution solution;
    string s = "coaching";
    string t = "coding";
    cout << solution.appendCharacters(s, t) << endl;
    return 0;
}
