#include<iostream>
using namespace std;

#define v 4
#define inf 99999


void print(int dist[][v]){
    for (int i = 0; i < v; i++)
    {
        cout<<endl;
        for (int j = 0; j < v; j++)
        {
            if(dist[i][j]==inf)  cout<<"INFINITE";
            else cout << dist[i][j] << " ";
        }
        
    }
    
}

void floydwarshal(int dist[][v]){
  int i,j,k;
  for (k=0;k<v;k++)   {
     for ( i = 0; i < v; i++)
     {
        for ( j = 0; j < v; j++)
        {
            if (dist[i][j] > (dist[i][k] + dist[k][j]))
            {
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        
     }
     
  }
   print(dist);
  
}


int main(){
    int graph[v][v] = {{0,5,inf,4},
                       {inf,0,5,inf},
                       {3,inf,0,inf},
                       {inf,inf,2,0}};

   floydwarshal(graph);                   
}