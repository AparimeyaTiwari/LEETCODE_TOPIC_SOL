#include <iostream>
using namespace std;


/*
void summation(int i,int n,int sum){
    if(i>n){
        cout<<sum;
        return;
    }
    sum += i;
    summation(i+1,n,sum);
}
*/
/*
a) Parmeterized
*/
void summation(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    summation(i-1,sum+i);

}

/*
b) Functional
*/

int fsum(int n){
    if(n==0){
        return 0;
    }
    return (n+fsum(n-1));
}


int main(){
    int n;
    cin>>n;
    summation(n,0);
    cout<<"\n";
    cout<<(fsum(n));
}