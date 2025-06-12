class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0;a*a<=c;a++){
            int d = c-(int)(a*a);
            if(binary_search(0,d,d))
                return true;
        }
       return false;
    }

    bool binary_search(long s,long e,int n){
        if(s>e){
            return false;
        }
        long mid = s+(e-s)/2;
        if(mid * mid == n){
            return true;
        }
        if(mid*mid<n){
            return binary_search(mid+1,e,n);
        }
        return binary_search(s+1,mid-1,n);
    }

};

/*int d = sqrt(c);//find range of a or b
        int i,j;
        map<int,int> mp;
        for(i = 0;i<=d;i++)
        {
            j = pow(i,2);
            mp.insert(make_pair(j,c-j));
        }
        for(auto &n:mp){
            if(mp.find(n.second) != mp.end()){
                return true;
            }
        }
        return false;
        */


 /*
 for(long a = 0;a*a<=c;a++){
            for(long b = 0;b*b<=c;b++){
                if(a*a+b*b ==c){
                    return true;
                }
            }
        }
        return false;
*/

        /*for(long a = 0;a*a<=c;a++){
        long d = c-(a*a);
        if(sqrt(d) == int(sqrt(d))){
            return true;
        }
       }
       return false;
        
    }
    */

 /*for(long a = 0;a*a<=c;a++){
            double b = c-a*a;
            double i = 1, sum = 0;
            while(sum<b){
                sum += i;
                i+=2;
            }
            if(sum == b){
                return true;
            }
        }
        return false;
        */


