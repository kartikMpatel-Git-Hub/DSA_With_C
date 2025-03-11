#include "../Stack/CHAR_STACK.c"
#include "CHAR_QUEUE.c"

void main(){
    int n = 5;
    QUEUE *q = createQueue(n);
    STACK *s = createStack(n);
    for(int i = 0; i < n; i++){
        enQueue(q,(char)(97+i));
    }
    displayQueue(q);
    while (!isEmptyQueue(q))
    {
        push(s,deQueue(q));
    }

    reSetQueue(q);

    while (!isEmptyStack(s))
    {
        enQueue(q,pop(s));
    }

    displayQueue(q);

}