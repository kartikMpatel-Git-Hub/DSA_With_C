// #include "IntGraph.c"
// #include "GraphWithMatrix.c"
#include "GraphWithLL.c"
int main(){
    int n = 6;
    Graph *g = createGraph(n);

    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,3);
    addEdge(g,2,4);
    addEdge(g,3,4);
    addEdge(g,3,5);
    // addEdge(g,4,5);

    displayGraph(g);
    dfs(g);
    bfs(g);
    // int n = 7;
    // Graph *g = createGraph(n);
    // addEdge(g,0,1);
    // addEdge(g,0,2);
    // addEdge(g,1,3);
    // addEdge(g,2,5);
    // addEdge(g,5,3);
    // addEdge(g,3,4);

    // displatyList(g);
    // dfs(g);
    // bfs(g);
    // int n = 7;
    // Node **graph = initiateGraph(n);

    // addNode(graph, 0, 1);
    // addNode(graph, 0, 2);
    // addNode(graph, 0, 3);
    // addNode(graph, 1, 4);
    // addNode(graph, 2, 4);
    // addNode(graph, 3, 5);
    // addNode(graph, 4, 6);
    // addNode(graph, 5, 6);

    // printGraph(graph, n);
    // printf("\n\nDFS : ");
    // dfs(graph,n,0);
    // printf("\n\nBFS : ");
    // bfs(graph,n,0);
    // return 0;
}