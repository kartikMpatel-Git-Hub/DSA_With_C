// #include "BinaryTree.c"
#include "BST.c"

int main(){
    BTree *t = createTree();
    int arr[] = {5,2,7,1,3,8,6,10,9,11};
    for(int i = 0; i < 10; i++){
        t->root = addNode(t->root,arr[i]);
    }
    printf("\n\n");
    preOrder(t->root);
    printf("\n\n");
    inOrder(t->root);
    printf("\n\n");
    postOrder(t->root);
    printf("\n\n");
    levelOrder(t->root);

    printf("\n\nTotal Node : %d",totalNode(t->root));
    printf("\n\nLevel Tree : %d",levelTree(t->root));
    printf("\n\nLeaf Node  : %d",leafNode(t->root));
    printf("\n\nInternal Node  : %d",internalNode(t->root));
    printf("\n\nSearch |11|  : %s",serachElement(t->root,11) ? "Found !" : "Not Found !");
    
}