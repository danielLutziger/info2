//
// Created by danie on 17.06.2023.
//

/**
* reverse even pseudo code

 Q = [14, 17, 16, 18, 21, 7, 28, 40]
 Q = [40, 17, 28, 18, 21, 7, 16, 14]

 Q = initQueue(): initializes a Queue
 enQueue(Q,x): inserts value x to queue Q (in the end)
 deQueue(Q): removes value from queue Q (in the beginning)
 queueSize(Q): returns the number of elements in queue Q

 Stack:
 S = initStack(): initializes a stack
 push(S,x): pushes value x onto stack S
 pop(S): removes value from stack S
 stackSize(S): returns the number of elements in stack S

 */

struct queue* reverseEven(struct queue* Q){
    // queue
    // init empty stack
    S = initStack();
    qSize = queueSize(Q);
    //create a stack with all the even numbers in it
    for(i = 1 to qSize){
        val = deQueue(Q);
        if(val % 2 == 0)
            push(S, val);
        enQueue(q, val);
    }
    // dequeue all elements from the queue and combine them with the stack
    for(i = 1 to qSize){
        val = deQueue(Q);
        if(val % 2 == 0)
            // if value is even, take the last element from the stack and enqueue it
            enqueue(q, pop(s))
        else
            enQueue(q, val);
    }
}