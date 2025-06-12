// CODE FOR 344(REVERSE IN PLACE)

/*app1)Index swap
swap the first index with last, 2nd->2nd last, 3rd->3rd last and so on
i)set i = 0 and j = length of s -1
ii) for loop -> i = 0,j=s.size()-1;i<j;i++,j--
    swap char at i and char at j position
    here->we swap characters at both ends of the array and simply increment->i decrement->j
iii)here we can either do:
    i<s.size()/2 or i<j
    since we run the loop till a)i is less than j or b)we run the loop total number of elements divided by 2 times
iv)done */

#include <iostream>
#include <vector>
using namespace std;
int main(){
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int j = size(s)-1;
        for(int i = 0;i<(size(s)+1)/2;i++)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            j--;
        }
     /*or*/
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        // Swap characters at positions i and j
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
};
return 0;
}
