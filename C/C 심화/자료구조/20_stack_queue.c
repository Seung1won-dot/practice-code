#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void init_stack(struct Stack* s) {
    s->top = -1;
}

int is_empty(struct Stack* s) {
    return s->top == -1;
}

int is_full(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack* s, int value) {
    if (is_full(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(struct Stack* s) {
    if (is_empty(s)) {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    return s->data[s->top--];
}

struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void init_queue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int is_queue_empty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear >= MAX_SIZE - 1) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (is_queue_empty(q)) {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    return q->data[q->front++];
}

int main() {
    struct Stack stack;
    init_stack(&stack);
    
    printf("=== 스택 ===\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("팝: %d\n", pop(&stack));
    printf("팝: %d\n", pop(&stack));
    printf("팝: %d\n", pop(&stack));
    
    struct Queue queue;
    init_queue(&queue);
    
    printf("\n=== 큐 ===\n");
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    
    printf("디큐: %d\n", dequeue(&queue));
    printf("디큐: %d\n", dequeue(&queue));
    printf("디큐: %d\n", dequeue(&queue));
    
    return 0;
}

