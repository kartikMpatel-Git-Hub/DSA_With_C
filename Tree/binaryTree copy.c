#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct
{
    Node *root;
}Tree;

Tree* createTree(){
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
} 

Node *createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* addNode(Node *root,int data){
    if(root == NULL){
        return createNode(data);
    }
    int choice = 0;
    printf("From Node %d Where You Want To Put Node %d  [1:left| 0: right] :",root->data,data);
    scanf("%d",&choice);
    if(choice){
        root->left = addNode(root->left,data);
    }
    else{
        root->right = addNode(root->right,data);
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
void postOrder(Node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);   
    postOrder(root->right);   
    printf("%d\t",root->data);
}
void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);   
    printf("%d\t",root->data);
    inOrder(root->right);   
}
int allNode(Node *root){
    if(root == NULL)
        return 0;
    return allNode(root->left) + allNode(root->right) + 1;
}

int heightOfTree(Node *root){
    if(root == NULL)
        return 0;
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    return ((left > right) ? left : right ) + 1; 
}
int externalNode(Node *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return externalNode(root->left) + externalNode(root->right);
}
int internalNode(Node *root){
    if(root == NULL || root->left == NULL && root->right == NULL)
        return 0;
    return internalNode(root->left) + internalNode(root->right) + 1;
}
void levelOrder(Node *root){
    Node *queue[allNode(root)];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        Node *curr = queue[front++];
        printf("%d\t",curr->data);
        if(curr->left != NULL)
            queue[rear++] = curr->left;
        if(curr->right != NULL)
            queue[rear++] = curr->right;
    }
}
void main(){
    Tree *t = createTree();
    int arr[] = {1,2,3,4,5,6};
    for(int i = 0; i < 6; i++){
        t->root = addNode(t->root,arr[i]);
    }
    printf("\nIn Order : ");
    inOrder(t->root);
    printf("\nPre Order : ");
    preOrder(t->root);
    printf("\nPost Order : ");
    postOrder(t->root);
    printf("\nLevel Order : ");
    levelOrder(t->root);

    printf("\nHight : %d",heightOfTree(t->root));
    printf("\nExternal  : %d",externalNode(t->root));
    printf("\nInternal Node  : %d",internalNode(t->root));
}

