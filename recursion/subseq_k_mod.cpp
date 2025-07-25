#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sum_k{
    public:
        vector<vector<int> > output;
        bool subseq_sum(int index,vector<int>& vec,vector<int>& ip,int sum,int target){
            bool val;
            if (index>=ip.size()){
                if(sum == target){
                    output.push_back(vec);
                    return true;
                }
                return false;
            }
            vec.push_back(ip[index]);
            sum += ip[index];
            if(subseq_sum(index+1,vec,ip,sum,target)==true);
            sum -= ip[index];
            vec.pop_back();
            subseq_sum(index+1,vec,ip,sum,target);
        }
};

int main(){
    vector<int> ip = {1,12,13,5,3,5};
    vector<int> vec;
    sum_k obj1;
    obj1.subseq_sum(0,vec,ip,0,13);
    for(auto i:obj1.output){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}