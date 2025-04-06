#include "LL.c"

void main(){
    
    // Queue *q = createQueue();
    // enQueue(q,1,4);
    // enQueue(q,2,2);
    // enQueue(q,3,3);
    // enQueue(q,4,1);
    // enQueue(q,5,5);
    // display(q);

    // 25->26->27->28->29->3->7
    LL *list = createList();
    insertLast(list,25);
    insertLast(list,26);
    insertLast(list,27);
    insertLast(list,28);
    insertLast(list,29);
    insertLast(list,3);
    insertLast(list,7);

    solve(list->head);

    printf("\n\n");
    displayRecursion(list->head);
    printf("\n\n");

    displayRecursion(list->head);





















    // LL *list = createList();

    // insertLast(list,10);
    // insertLast(list,20);
    // insertLast(list,30);
    // insertLast(list,40);
    // insertIdx(list,0,1000);
    // // insertFirst(list,100);
    // // // insertFirst(list,100);
    // display(list);
    // displayRev(list);

    // // deleteFirst(list);
    // display(list);
    // displayRev(list);

    // deleteLast(list);
    // // printf("\nHello");
    // deleteLast(list);
    // deleteLast(list);
    // deleteLast(list);
    // deleteLast(list);
    // display(list);
    // displayRev(list);
}