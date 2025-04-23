#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int **arr;
    int vertex;
    /* data */
}Graph;

Graph *createGraph(int n){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->vertex = n;
    g->arr = (int**)calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++){
        g->arr[i] = (int*)calloc(n,sizeof(int));
    }
    return g;
}

void addEdge(Graph *g,int source,int destination){
    g->arr[source][destination] = 1; 
    g->arr[destination][source] = 1; 
}

void printMatrix(Graph *g){
    for(int i = 0; i < g->vertex; i++){
        for(int j = 0; j < g->vertex; j++){
            printf("%d\t",g->arr[i][j]);
        }
        printf("\n");
    }
}

void bfsHelper(Graph *g,int start,int visited[]){
    visited[start] = 1;
    int *queue = (int*)calloc(g->vertex,sizeof(int));
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    while(front < rear){
        int data = queue[front++];
        printf("%d\t",data);
        for(int i = 0; i < g->vertex; i++){
            if(g->arr[data][i] && !visited[i]){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void bfs(Graph *g){
    int *visited = (int*)calloc(g->vertex,sizeof(int));
    bfsHelper(g,0,visited);
}

void dfsHelper(Graph *g,int start,int visited[]){
    visited[start] = 1;
    printf("%d\t",start);
    for(int i = 0; i < g->vertex; i++){
        if(g->arr[start][i] == 1 && !visited[i]){
            dfsHelper(g,i,visited);
        }
    }
}

void dfs(Graph *g){
    int *visited = (int*)calloc(g->vertex,sizeof(int));
    dfsHelper(g,0,visited);
}

void main(){
    int n = 6;
    Graph *g = createGraph(n);
    addEdge(g,0,1);
    addEdge(g,0,2);
    // addEdge(g,1,2);
    addEdge(g,1,3);
    // addEdge(g,2,1);
    addEdge(g,2,4);
    addEdge(g,3,5);

    // printMatrix(g);
    printf("\n\n");
    dfs(g);
    printf("\n\n");
    bfs(g);
}
