#include "Graph.c"
int main(){
    int n = 5;

    GraphMatrix *m = createGraphMatrix(n);
    addEdgeMatrix(m,0,1);
    addEdgeMatrix(m,0,2);
    addEdgeMatrix(m,1,3);
    addEdgeMatrix(m,2,3);
    addEdgeMatrix(m,3,4);
    displatyMatrix(m);
    degreeOfVertexMatrix(m);
    dfsMatrix(m);
    bfsMatrix(m);

    GraphLL *g = createGraphLL(n);
    addEdgeLL(g,0,1);
    addEdgeLL(g,0,2);
    addEdgeLL(g,1,3);
    addEdgeLL(g,2,3);
    addEdgeLL(g,3,4);
    displayGraphLL(g);
    degreeOfVertexLL(g);
    dfsLL(g);
    bfsLL(g);
}