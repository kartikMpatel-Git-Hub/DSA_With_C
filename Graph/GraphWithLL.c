#include "stdio.h"
#include "stdlib.h"
// #include "../LinkedList/QueueLL.c"
#include "../LinkedList/LL.c"



typedef struct{
    LL *list;
    int vertex;
}Graph;

Node* createSNode(int destination){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = destination;
    newNode->next = NULL;
    return newNode;
}

void insertNode(LL *list,int data){
    Node *newNode = createSNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

Graph *createGraph(int vertex){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->vertex = vertex;
    g->list = (LL*)calloc(vertex,sizeof(LL));
    for(int i = 0; i < vertex; i++){
        g->list[i].head = NULL;
    }

    return g;
}

void addEdge(Graph *g,int source,int destination){
    Node *newNode = createSNode(destination);
    newNode->next = g->list[source].head;
    g->list[source].head = newNode;

    newNode = createSNode(source);
    newNode->next = g->list[destination].head;
    g->list[destination].head = newNode;
    
    // insertNode(g->list[source],destination); 
    // insertNode(g->list[destination],source); 
}
void dfsUtil(Graph *g,int start,int *visited){
    visited[start] = 1;
    printf("%d\t",start);
    Node *temp = g->list[start].head;
    while (temp)
    {
        if(!visited[temp->data])
            dfsUtil(g,temp->data,visited);
        temp = temp->next;
    }
}
void dfs(Graph *g){
    int* visited = (int*)calloc(g->vertex,sizeof(int));
    dfsUtil(g,0,visited);
}
void bfsUtil(Graph *g,int start,int *visited){
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
void bfs(Graph *g){
    int* visited = (int*)calloc(g->vertex,sizeof(int));
    printf("\n\n");
    bfsUtil(g,0,visited);
}


void displayGraph(Graph *g){
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