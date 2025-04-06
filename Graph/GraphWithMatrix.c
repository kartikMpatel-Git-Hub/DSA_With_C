#include "stdio.h"
#include "stdlib.h"
#include "../LinkedList/QueueLL.c"

typedef struct{

    int **list;
    int vertexs;
}Graph;

Graph *createGraph(int vertexs){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->list = (int**)calloc(vertexs,sizeof(int*));
    g->vertexs = vertexs;
    for(int i = 0; i < vertexs; i++){
        g->list[i] = (int*)calloc(vertexs,sizeof(int));
    }
    return g;
}

void addEdge(Graph *g,int source,int destination){
    g->list[source][destination] = 1;
    // g->list[destination][source] = 1;
}

void displatyList(Graph *g){
    for(int i = 0; i < g->vertexs; i++){
        for(int j = 0; j < g->vertexs; j++){
            printf("%d ",g->list[i][j]);
        }
        printf("\n");
    }
}

void dfsUtil(Graph *g,int start,int visited[]){
    visited[start] = 1;
    printf("%d\t",start);
    for(int i = 0; i < g->vertexs; i++){
        if(g->list[start][i] == 1 && !visited[i]){
            dfsUtil(g,i,visited);
        }
    }
}

void dfs(Graph *g){
    int n = g->vertexs;
    int *visited = (int*)calloc(g->vertexs,sizeof(int));
    dfsUtil(g,0,visited);
}

void bfsUtil(Graph *g,int start,int visited[]){
    visited[start] = 1;
    Queue *q = createQueue();
    enQueue(q,start);
    printf("\n");
    while (!isEmpty(q))
    {
        int data = deQueue(q);
        printf("%d\t",data);
        for(int i = 0; i < g->vertexs; i++){
            if(g->list[data][i] == 1 && !visited[i]){
                enQueue(q,i);
                visited[i] = 1;
            }
        }
    }
    
}
void bfs(Graph *g){
    int n = g->vertexs;
    int *visited = (int*)calloc(g->vertexs,sizeof(int));
    bfsUtil(g,0,visited);
}