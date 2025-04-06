// #include "SingleLinkedList.c"
// #include "StackLL.c"
// #include "QueueLL.c"
// #include "CLLCHAR.c"
// #include "DLLSTUDENT.c"
#include "DLLT.c"

void main(){

    LL* list = createList();
    insertLast(list,1);
    insertLast(list,2);
    insertLast(list,3);
    insertLast(list,4);
    insertLast(list,5);

    display(list);
    displayRev(list);

    reveserList(list);
    display(list);
    displayRev(list);
    // LL *list = createList();
    // insertLast(list,"101","Kartik","Male");
    // insertLast(list,"102","Kartik1","Male");
    // insertLast(list,"103","Kartik2","Female");
    // insertLast(list,"104","Kartik3","Male");

    // display(list);
    // LL *list = createList();
    // insertLast(list,'a');
    // insertLast(list,'b');
    // insertLast(list,'c');
    // insertLast(list,'d');
    // insertLast(list,'e');
    // insertLast(list,'f');
    // insertLast(list,'g');

    // display(list);
    // deleteLast(list);
    // display(list);
    // deleteFirst(list);
    // display(list);

    
    /*SingleLinkedList *list;
    display(list);

    list = createList();
    display(list);

    insertFirst(list,10);
    insertFirst(list,20);
    insertFirst(list,30);
    insertFirst(list,40);

    insertLast(list,100);

    display(list);

    deleteFirst(list);
    display(list);

    deleteLast(list);
    deleteLast(list);
    deleteLast(list);
    deleteLast(list);
    display(list);
    
    
    insertFirst(list,10);
    insertFirst(list,20);
    display(list);

    SingleLinkedList *list = createList();

    insertLast(list,10);
    insertLast(list,20);
    insertLast(list,30);
    insertLast(list,40);
    insertLast(list,50);
    insertLast(list,60);

    display(list);
    reverseLinkedList(list);
    display(list);
    printf("\n\nMiddle Is : %d",middleElement(list)->data);

    Stack *stack = createStack();

    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    push(stack,50);

    display(stack);

    printf("\n\nPoped Element : %d",pop(stack));
    display(stack);

    SingleLinkedList *list = createList();
    insertLast(list,10);
    insertLast(list,20);
    insertLast(list,30);
    insertLast(list,40);
    insertLast(list,50);
    insertLast(list,60);
    insertLast(list,70);

    display(list);
    
    swap(list,-1,6);
    display(list);

    SingleLinkedList *l1 = createList();
    SingleLinkedList *l2 = createList();

    // insertLast(l1,2);
    // insertLast(l1,3);
    // insertLast(l1,1);

    insertLast(l2,4);
    insertLast(l2,5);

    display(l1);
    display(l2);

    concatenate(l1,l2);

    display(l1);
    display(l2);

    SingleLinkedList *list = createList();
    insertLast(list,10);
    insertLast(list,20);
    insertLast(list,30);
    insertLast(list,40);
    insertLast(list,50);


    insertFirst(list,100);
    insertFirst(list,200);
    insertFirst(list,300);
    insertFirst(list,400);
    insertFirst(list,500);
    display(list);
    
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    display(list);

    deleteLast(list);
    deleteLast(list);
    deleteLast(list);
    // deleteLast(list);
    display(list);

    Queue *queue = createQueue();
    enQueue(queue,10);
    enQueue(queue,20);
    enQueue(queue,30);
    enQueue(queue,40);
    enQueue(queue,50);

    display(queue);
    
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    display(queue);*/
}