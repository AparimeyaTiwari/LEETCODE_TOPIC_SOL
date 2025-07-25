#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

void mat(int n, int m,vector<vector<int>> adjmatrix){
    int u,v;
    for(int i = 0;i<m;i++){
        cout<<"Enter edge: ";
        cin>>u>>v;
        adjmatrix[u][v] = 1;
        adjmatrix[v][u] = 1;
    }

    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<n+1;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}

void list(int n,int m,vector<int> adjlist[]){
    int u,v;
    for(int i = 0;i<m;i++){
        cout<<"Enter edge: ";
        cin>>u>>v;
        adjlist[u].push_back(v);
        //adjlist[v].push_back(u); -> For undirected graph 
    }
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<" ";
        }
        cout<<"\n";
    }

}
int main(){
    //ADJACENCY MATRIX
    int m,n;
    cout<<"Enter the number of vertex and edges: ";
    cin>>n>>m;
    vector<vector<int>> adjmatrix(n+1,vector<int>(n+1,0));
    mat(n,m,adjmatrix);
    cout<<"Enter the number of vertex and edges: ";
    cin>>n>>m;
    cout<<"\nADJACENCY LIST\n";
    //ADJACENCY LIST
    vector<int> adjlist[n+1];
    list(n,m,adjlist);
    return 0;
}