#include <iostream>
#include <string>
using namespace std;


/*
Q1) Print Name 5 times 
a) For loop
*/
//b) Recursion 
//I) MY approach
int cnt = 0;
void name(string n){
    if(cnt == 5){
        return;
    }
    cout<<n<<" ";
    cnt++;
    name(n);
}
//II) Striver
void print(int i,int n){
    if(i>n){
        return;
    }
    cout<<"Aparimeya"<<" ";
    print(i+1,n);
}

/*
Q2) Print linearly from 1 to n
*/
//I) My approach 
int i = 1;
void linear(int n){
    if(i == n+1){
        return;
    }
    cout<<i<<" ";
    i ++;
    linear(n);
}

//II) Striver
void printnum(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    printnum(i+1,n);
}

/*
Q3) Print from N to 1
*/
//I) My Approach
void rev(int m){
    if(m == 0){
        return;
    }
    cout<<m<<" ";
    m--;
    rev(m);
}

void printrev(int i, int n){
    if(i<1){
        return;
    }
    cout<<i<<" ";
    printrev(i-1,n);
}

/* Q4) FROM 1 TO N without + (Backtracking)*/
//I) Stirver
void bctprintnum(int i,int N){
    if(i<1){
        return;
    }
    bctprintnum(i-1,N);
    cout<<i<<" ";
}

/* Q4) FROM N TO 1 without - (Backtracking)*/
//I) Stirver
void bctrev(int i,int N){
    if(i>N){
        return;
    }
    bctrev(i+1,N);
    cout<<i<<" ";
}

int main(){
    string n = "Aparimeya";
    cout<<"Q1"<<endl;
    name(n);
    cout<<endl;
    print(1,5);
    cout<<endl;
    cout<<"Q2"<<endl;
    int num = 10;
    linear(num);
    cout<<"\n";
    printnum(1,num);
    cout<<"\n";
    cout<<"Q3"<<endl;
    rev(num);
    cout<<"\n";
    printrev(num,num);
    cout<<"\n";
    cout<<"Q4"<<endl;
    bctprintnum(num,num);
    cout<<"\n";
    cout<<"Q5"<<endl;
    bctrev(1,num);
}