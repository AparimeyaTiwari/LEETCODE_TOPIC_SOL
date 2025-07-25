#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

void list(int n,int m,vector<int> adjlist[]){
    int u,v;
    for(int i = 0;i<m;i++){
        cout<<"Enter edge: ";
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u); //-> For undirected graph 
    }
    for(int i = 0;i<n;i++){
        cout<<i<<"-> ";
        cout<<"{ ";
        for(int j = 0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<",";
        }
        cout<<" }";
        cout<<"\n";
    }

}

void dfs(vector<int> adjlist[],int node,vector<bool> &visited,vector<int> &op){
    if(visited[node] == true){
        return;
    }
    op.push_back(node);
    visited[node] = true;
    for(auto x:adjlist[node]){
        dfs(adjlist,x,visited,op);
    }
}
int main(){
    int n,m;
    cout<<"Enter the number of vertex and edges: ";
    cin>>n>>m;
    cout<<"\nADJACENCY LIST\n";
    //ADJACECY LIST
    vector<int> answer;
    vector<int> adjlist[n];
    vector<bool> visited(n,false);
    list(n,m,adjlist);
    dfs(adjlist,0,visited,answer);
    cout<<"DFS IS: "<<endl;
    for(auto x:answer){
        cout<<x<<" ";
    }
    return 0;
}