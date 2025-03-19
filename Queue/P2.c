#include "../Stack/CHAR_STACK.c"
#include "CHAR_QUEUE.c"


void reverseQueue(QUEUE *q){
    
    STACK *s = createStack(q->size);
    while (!isEmptyQueue(q))
    {
        push(s,deQueue(q));
    }

    reSetQueue(q);

    while (!isEmptyStack(s))
    {
        enQueue(q,pop(s));
    }

}
void main(){
    int n = 5;
    QUEUE *q = createQueue(n);
    for(int i = 0; i < n; i++){
        enQueue(q,(char)(97+i));
    }
    displayQueue(q);
    
    reverseQueue(q);
    displayQueue(q);

}