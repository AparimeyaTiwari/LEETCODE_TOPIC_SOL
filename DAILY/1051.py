class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        cnt = 0
        expect = sorted(heights)
        for i in range(len(expect)):
            if(expect[i] != heights[i]):
                cnt += 1
        return cnt
        
