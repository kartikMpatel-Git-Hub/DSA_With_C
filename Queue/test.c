#include "DUBLEENDED_QUEUE.c"

void main(){
    int n = 5;
    QUEUE *q = createQueue(n);
    enQueue(q,'a');
    enQueue(q,'b');
    enQueue(q,'c');
    enQueue(q,'d');
    enQueue(q,'e');
    displayQueue(q);
    
    deQueue(q);
    displayQueue(q);
    deQueueLast(q);
    displayQueue(q);
    
    enQueueFirst(q,'z');
    displayQueue(q);
    enQueue(q,'x');
    displayQueue(q);
}