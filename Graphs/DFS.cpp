#include<iostream>
#include<stack>
using namespace std;

const int maxnodes=10;
bool visited[maxnodes];
bool adjacencymatrix[maxnodes][maxnodes];

void DFS(int currentnode, int totalnodes) {
    visited[currentnode] = true;
    cout << currentnode << " ";

    for (int i = 0; i < totalnodes; i++) {
        if (adjacencymatrix[currentnode][i] == true && !visited[i]) {
            DFS(i, totalnodes);
        }
    }
}

int main() {
    int totalnodes, edges;
    cout << "enter no. of nodes:";
    cin >> totalnodes;

    cout << "enter no. of edges:";
    cin >> edges;

    // Define the adjacency matrix with false
    for (int i = 0; i < totalnodes; i++) {
        for (int j = 0; j < totalnodes; j++) {
            adjacencymatrix[i][j] = false;
        }
    }

    cout << "enter the edges (u,v)" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjacencymatrix[u][v] = true;
        adjacencymatrix[v][u] = true; // For undirected graph, to visit both side a-->b & b-->a
    }

    cout << "enter the starting node:";
    int startnode;
    cin >> startnode;

    // DFS traversal
    DFS(startnode, totalnodes);
}