#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
}LL;

typedef struct{
    LL *list;
    int v;
}Graph;

LL *createLL(){
    LL *l = (LL*)malloc(sizeof(LL));
    l->head = NULL;
    l->tail = NULL;

    return l;
}
Node *createNode(int data){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    return n;
}
Graph *createGraph(int n){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->list = (LL*)calloc(n,sizeof(LL));
    for(int i = 0; i < n; i++){
        g->list[i].head = NULL;
    }
    g->v = n;
    return g;
}

void addEdge(Graph *g,int source,int destination){
    Node *temp = createNode(destination);
    temp->next = g->list[source].head;
    g->list[source].head = temp;

    temp = createNode(source);
    temp->next = g->list[destination].head;
    g->list[destination].head = temp;
}

void display(Graph *g){
    
    for(int i = 0; i < g->v; i++){
        Node *temp = g->list[i].head;
        printf("\nNode %d :",i);
        while (temp)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}


void bfsHelper(Graph *g,int start,int visited[]){
    int *queue = (int*)calloc(g->v,sizeof(int));
    int front = 0; 
    int rear = 0;
    visited[start] = 1;
    queue[rear++] = start; 
    while (front < rear)
    {
        int data = queue[front++];
        printf("%d\t",data);
        Node *temp = g->list[data].head;
        while (temp)
        {
            if(!visited[temp->data]){
                queue[rear++] = temp->data;
                visited[data] = 1;
            }
            temp = temp->next;
        }
    }
    
}


void dfsHelper(Graph *g,int start,int visited[]){
    visited[start] = 1;
    printf("%d\t",start);
    Node *temp = g->list[start].head;
    while (temp)
    {
        if(!visited[temp->data]){
            dfsHelper(g,temp->data,visited);
        }
        temp = temp->next;
    }
    
}

void bfs(Graph *g){
    int *visited = (int*)calloc(g->v,sizeof(int));
    bfsHelper(g,0,visited);
}

void dfs(Graph *g){
    int *visited = (int*)calloc(g->v,sizeof(int));
    dfsHelper(g,0,visited);
}
void main(){
    int n = 6;
    Graph *g = createGraph(n);
    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,1,3);
    addEdge(g,2,4);
    addEdge(g,3,5);

    // display(g);
    printf("\n\n");
    dfs(g);
    printf("\n\n");
    bfs(g);
}