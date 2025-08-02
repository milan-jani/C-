#include<iostream>
#include<queue>
using namespace std;

const int maxnodes=10;
bool visited[maxnodes];
bool adjacencymatrix[maxnodes][maxnodes];


void BFS(int startnode,int totalnodes){
    queue<int> q;
    visited[startnode]=true;
    q.push(startnode);
    
    while (!q.empty()){

        int currentnode;
        currentnode=q.front();
        q.pop();
        cout<<currentnode<<" ";

        for (int i = 0; i < totalnodes; i++)
        {
            if(adjacencymatrix[currentnode][i]==true && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
        
    }
    
   

}


int main(){
    int totalnodes,edges;
    cout<<"enter no. of nodes:";
    cin>>totalnodes;

    cout<<"enter no. of edges:";
    cin>>edges;

    //define the adjacency matrix with false
    for (int i = 0; i < totalnodes; i++)
    {
        for (int j = 0; j < totalnodes; j++)
        {
           adjacencymatrix[i][j]=false;
           
        }
        
    }
    cout<<"enter the edges (u,v)"<<endl;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjacencymatrix[u][v]=true;
        adjacencymatrix[v][u]=true;//for undirected graph ,to visit both side a-->b & b-->a

    }

    cout<<"enter the starting node:";
    int startnode;
    cin>>startnode;
    //BFS traversal
    BFS(startnode,totalnodes);
   


}