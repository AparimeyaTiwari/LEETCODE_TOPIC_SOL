import sys
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minprice = sys.maxsize
        currpro = 0
        maxpro = 0
        for i in range(len(prices)):
            if(prices[i]<minprice):
                minprice = prices[i]
            currpro = prices[i]-minprice
            if(currpro>maxpro):
                maxpro = currpro
        return maxpro
            




'''pro = 0
        maxpro = 0
        for i in range(len(prices)-1):
            for j in range(i,len(prices)):
                pro = prices[j]-prices[i]
                if(pro>maxpro and pro>0):
                    maxpro = pro
        return maxpro'''
''' j = 0
        pro = 0
        maxpro = 0
        for i in range(len(prices)-1,-1,-1):
            pro = max(prices[j:len(prices)])-prices[j]
            if(pro >maxpro):
                maxpro = pro
            j += 1
        return maxpro'''
