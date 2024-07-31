class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int t = 0;
        int b = m-1;
        int mid;
        while(t<=b){
            mid = (t+b)/2;
            if(matrix[mid][0]<target && matrix[mid][matrix[mid].size()-1]>target){
                break;
            }
            else if(matrix[mid][0]>target){
                b = mid-1;
            }
            else{
                t = mid+1;
            }
        }
        int row = (t+b)/2;
        int l = 0;
        int r = matrix[row].size()-1;

        while(l<=r){
            mid = (l+r)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid]<target){
                l = mid+1;

            }
            else{
                r = mid-1;
            }
        }
        return false;
    
        }
    };





/*int i = 0;
        int j = 0;
        for(i = 0;i<matrix.size();i++){
            for(j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
        */

 /*int i = 0;
        int j = matrix[0].size()-1;
        while(i>=0 && i<matrix.size() && j>= 0 && j<matrix[0].size()){
            if(matrix[i][j]<target){
                i++;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
        */
