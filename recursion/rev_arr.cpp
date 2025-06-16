#include <iostream>
#include <algorithm>
using namespace std;


void swap(int &a,int &b){
    /*a = a+b;
    b = a-b;
    a = a-b;*/
    int temp = a;
    a = b;
    b = temp;
}

void rev(int arr[],int l,int r){
    if(l>=r) return;
    swap(arr[l],arr[r]);
    rev(arr,l+1,r-1);
}

void onepointer(int arr[],int l, int n){
    //if(l>=n-1-l) return;
    //or just stop when middle(n/2)
    if(l>=n/2) return;
    swap(arr[l],arr[n-1-l]);
    onepointer(arr,l+1,n);
}

int main(){
    int arr[5] = {1,22,19,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rev(arr,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    onepointer(arr,0,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
