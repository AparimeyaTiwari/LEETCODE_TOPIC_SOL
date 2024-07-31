/*
 Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

  

 Example 1:

 Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 Output: 8
 Explanation: There are 8 negatives number in the matrix.
 Example 2:

 Input: grid = [[3,2],[1,0]]
 Output: 0
  

 Constraints:

 m == grid.length
 n == grid[i].length
 1 <= m, n <= 100
 -100 <= grid[i][j] <= 100
 */

/*O(m+n) approach(since in while loop in worst case we will have to dec j n times and inc i m times*/
/*
 logic: since non-dec:
    if(value<0) all values below it zero
    here, we start off with the last value
 */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(); //intilization statement
        int n = grid[0].size();
        int i = 0; // i is set to first row
        int j = n-1; //j is set to last coloumn
        int count = 0;
        while(i>=0 && i<m && j>=0 && j<n){ //this loop will only run m+n in worst case
            cout<<"i: "<<i<<" j: "<<j<<endl;
            if(grid[i][j]< 0){
                count += m-i; //if the number is -ve all numbers below it -ve
                cout<<count<<endl; //this would be given by m-i since(i starts at 0)
                j--; //now move to the left
            }
            else{
                i++; //will only find negative element down below
            }
        }
        return count;
    }
};









/*
 APP 1(BRUTE FORCE APP)
 ->simply traverse and find all negatives
 */
 for(auto &n:grid){
            for(auto &num:n){
                if(num<0){
                    count ++;
                }
            }
        }
        return count;


/*
 APP2(BRUTE FORCE BUT DIFFERENT)
 ->use circular queue logic:
 i = 0
 i++
 if(i == m) then j ++ (since we have traversed the jth coloumn at this point)
 i = i%m(so that we never get i>=m)
 same as before -> count negative !!
*/
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = 0; //for row
        int j = 0; //for col
        while(j<n){
            if(grid[i][j]<0){
                count ++;
            }
            i++;
            if(i == m){
                j ++;
            }
            i = i%m;
        }
        return count;
    
        
