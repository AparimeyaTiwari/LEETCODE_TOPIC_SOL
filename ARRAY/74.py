class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        t = 0
        b = len(matrix)-1
        while(t<=b):
            mid = (t+b)//2
            if(matrix[mid][0]<target and matrix[mid][-1]>target):
                break
            elif(matrix[mid][0]>target):
                b = mid-1
            elif(matrix[mid][-1]<target):
                t = mid+1

        row = mid
        l = 0
        r = len(matrix[row])-1

        while(l<r):
            mid = (l+r)//2
            if(matrix[row][mid] == target):
                return True
            elif(matrix[row][mid]<target):
                l = mid+1
            else:
                r = mid-1
        return False
        return False
