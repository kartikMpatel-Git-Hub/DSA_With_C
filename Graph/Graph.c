#include "stdio.h"
#include "stdlib.h"
#include "../LinkedList/LL.c"

typedef struct{

    int **matrix;
    int vertexs;
}GraphMatrix;


typedef struct{
    LL *list;
    int vertex;
}GraphLL;


Node* createListNode(int destination){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = NULL;
    return newNode;
}

void insertNode(LL *list,int data){
    Node *newNode = createListNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

GraphMatrix *createGraphMatrix(int vertexs){
    GraphMatrix *g = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    g->matrix = (int**)calloc(vertexs,sizeof(int*));
    g->vertexs = vertexs;
    for(int i = 0; i < vertexs; i++){
        g->matrix[i] = (int*)calloc(vertexs,sizeof(int));
    }
    return g;
}

GraphLL *createGraphLL(int vertex){
    GraphLL *g = (GraphLL*)malloc(sizeof(GraphLL));
    g->vertex = vertex;
    g->list = (LL*)calloc(vertex,sizeof(LL));
    for(int i = 0; i < vertex; i++){
        g->list[i].head = NULL;
    }

    return g;
}

void addEdgeMatrix(GraphMatrix *g,int source,int destination){
    g->matrix[source][destination] = 1;
    g->matrix[destination][source] = 1;
}

void addEdgeLL(GraphLL *g,int source,int destination){
    Node *newNode = createListNode(destination);
    newNode->next = g->list[source].head;
    g->list[source].head = newNode;

    newNode = createListNode(source);
    newNode->next = g->list[destination].head;
    g->list[destination].head = newNode;
}

void displatyMatrix(GraphMatrix *g){
    printf("\n\n");
    for(int i = 0; i < g->vertexs; i++){
        for(int j = 0; j < g->vertexs; j++){
            printf("%d ",g->matrix[i][j]);
        }
        printf("\n");
    }
}

void displayGraphLL(GraphLL *g){
    for(int i = 0; i < g->vertex; i++){
        Node* temp = g->list[i].head;
        while (temp)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void degreeOfVertexMatrix(GraphMatrix *g){
    for(int i = 0; i < g->vertexs; i++){
        int count = 0;
        for(int j = 0; j < g->vertexs; j++){
            if(g->matrix[i][j] == 1)
                count++;
        }
        printf("\nVertex %d Has Total %d Degree !",i,count);
    }
}
void degreeOfVertexLL(GraphLL *g){
    for(int i = 0; i < g->vertex; i++){
        Node* temp = g->list[i].head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        printf("\nVertex %d Has Total %d Degree !",i,count);
    }
}

void dfsUtilMatrix(GraphMatrix *g,int start,int visited[]){
    visited[start] = 1;
    printf("%d\t",start);
    for(int i = 0; i < g->vertexs; i++){
        if(g->matrix[start][i] == 1 && !visited[i]){
            dfsUtilMatrix(g,i,visited);
        }
    }
}

void dfsMatrix(GraphMatrix *g){
    int n = g->vertexs;
    int *visited = (int*)calloc(g->vertexs,sizeof(int));
    dfsUtilMatrix(g,0,visited);
}

void dfsUtilLL(GraphLL *g,int start,int *visited){
    visited[start] = 1;
    printf("%d\t",start);
    Node *temp = g->list[start].head;
    while (temp)
    {
        if(!visited[temp->data])
            dfsUtilLL(g,temp->data,visited);
        temp = temp->next;
    }
}

void dfsLL(GraphLL *g){
    int* visited = (int*)calloc(g->vertex,sizeof(int));
    dfsUtilLL(g,0,visited);
}

void bfsUtilMatrix(GraphMatrix *g,int start,int visited[]){
    visited[start] = 1;
    LL *q = createList();
    enQueue(q,start);
    printf("\n");
    while (!isEmpty(q))
    {
        int data = deQueue(q);
        printf("%d\t",data);
        for(int i = 0; i < g->vertexs; i++){
            if(g->matrix[data][i] == 1 && !visited[i]){
                enQueue(q,i);
                visited[i] = 1;
            }
        }
    }
    
}

void bfsMatrix(GraphMatrix *g){
    int n = g->vertexs;
    int *visited = (int*)calloc(g->vertexs,sizeof(int));
    bfsUtilMatrix(g,0,visited);
}

void bfsUtilLL(GraphLL *g,int start,int *visited){
    visited[start] = 1;
    LL *q = createList();
    enQueue(q,start);
    while (!isEmpty(q))
    {
        int data = deQueue(q);
        printf("%d\t",data);
        Node *temp = g->list[data].head;
        while (temp)
        {
            if(!visited[temp->data]){
                enQueue(q,temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
        
    }
}

void bfsLL(GraphLL *g){
    int* visited = (int*)calloc(g->vertex,sizeof(int));
    printf("\n\n");
    bfsUtilLL(g,0,visited);
}