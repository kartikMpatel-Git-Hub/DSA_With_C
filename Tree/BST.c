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
    if(root->data < data){
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
    printf("%d\t",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d\t",root->data);
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t",root->data);
}

int totalNode(Node *root){
    if(root == NULL){
        return 0;
    }
    int left = totalNode(root->left);
    int right = totalNode(root->right);
    return left + right + 1;
}

int leafNode(Node *root){
    if(root->left == NULL && root->right == NULL)
        return 1;
    int left = 0 , right = 0;
    if(root->left != NULL)
        left = leafNode(root->left);
    if(root->right != NULL)
        right = leafNode(root->right);
    return left + right;
}
int internalNode(Node *root){
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int left = 0 , right = 0;
    if(root->left != NULL)
        left = internalNode(root->left);
    if(root->right != NULL)
        right = internalNode(root->right);
    return left + right  + 1;
}

void levelOrder(Node *root){
    int n = totalNode(root);
    Node *queue[n];
    queue[0] = root;
    int idx = 0;
    int next = 1;
    while(idx < n){
        Node *temp = queue[idx++];
        printf("%d\t",temp->data);
        if(temp->left != NULL)
            queue[next++] = temp->left;
        if(temp->right != NULL)
            queue[next++] = temp->right;
    }
}
int levelTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int left = levelTree(root->left);
    int right = levelTree(root->right);
    return (left > right) ? left + 1 : right + 1;
}

int serachElement(Node *root,int key){
    if(root == NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    else if(root->data < key){
        return serachElement(root->right,key);
    }
    else{
        return serachElement(root->left,key);
    }
    return 0;
}