#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct{
    Node *root;
}BTree;

BTree *createTree(){
    BTree *t = (BTree*)malloc(sizeof(BTree));
    t->root = NULL;
    return t;
}

Node *createNode(int data){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

Node *addNode(Node *root,int data){
    if(root == NULL){
        Node* n = createNode(data);
        return n;
    }
    int choice = 0;
    printf("Enter Where You Want To Enter Left[0]|Right[1] Root %d  Current %d :",root->data,data);
    scanf("%d",&choice);
    if(choice){
        root->right = addNode(root->right,data);
    }
    else{
        root->left = addNode(root->left,data);
    }

    return root;
}
void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}


