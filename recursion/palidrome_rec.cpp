#include <iostream>
#include <string>
using namespace std;


bool palindrome(string s,int l,int n){
    if(l>=n-1-l) return true;
    if(s[l]!=s[n-1-l]) return false;
    return palindrome(s,l+1,n-1-l);
}

int main(){
    string st = "markram";
    cout<<palindrome(st,0,st.size());
}