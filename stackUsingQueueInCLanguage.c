#include<stdio.h>
#include<stdlib.h>
#define n 100

struct queue{
    int *arr;
    int front;
    int back;
};

void initialize(struct queue** qe){
    (*qe) = (struct queue*)malloc(sizeof(struct queue));
    if(!(*qe)){
        printf("Queue is not initialized\n");
        exit(1);
    }
    (*qe)->arr = (int *)malloc(n * sizeof(int));
    if(!(*qe)->arr){
        printf("Queue array is not initialized\n");
        exit(1);
    }
    (*qe)->front = -1;
    (*qe)->back = -1;
}

void enqueue(struct queue** qe, int val){
    if((*qe)->back == n-1){
        printf("stack is full\n");
        return;
    }
    (*qe)->arr[++(*qe)->back] = val;
    if((*qe)->front == -1){
        (*qe)->front++;
    }
}

void dequeue(struct queue** qe){
    if((*qe)->front == -1 || (*qe)->front > (*qe)->back){
        printf("Satck is empty");
        return;
    }
    (*qe)->front++;
    if ((*qe)->front > (*qe)->back) {
        (*qe)->front = -1;
        (*qe)->back = -1;
    }
}

int peek(struct queue* qe){
    if((qe)->front == -1 || (qe)->front > (qe)->back){
        printf("Stack is empty");
        return -1;
    }
    return ((qe)->arr[(qe)->front]);
}

int empty(struct queue* qe) {
    return (qe->front == -1 || qe->front > qe->back);
}

int size(struct queue* qe){
    return qe->back - qe->front + 1;
}

void push(struct queue** qe, int val){
    enqueue(qe,val);
}

void pop(struct queue** qe){
    struct queue* temp;
    initialize(&temp);
    while(size((*qe)) > 1){
        enqueue(&temp,peek(*qe));
        dequeue(qe);
    }
    dequeue(qe);
    while(!empty(temp)){
        enqueue(qe,peek(temp));
        dequeue(&temp);
    }
    free(temp->arr);
    free(temp);
}

int top(struct queue** qe){
    struct queue* temp;
    initialize(&temp);
    while(size(*qe) > 1){
        enqueue(&temp,peek(*qe));
        dequeue(qe);
    }
    int tem = peek(*qe);
    enqueue(&temp, tem);
    dequeue(qe);
    while(!empty(temp)){
        enqueue(qe,peek(temp));
        dequeue(&temp);
    }
    free(temp->arr);
    free(temp);
    return tem;
}

/* void push(struct queue** qe, int val) {
    enqueue(qe, val);
    int s = size(*qe);
    for (int i = 0; i < s - 1; i++) {
        enqueue(qe, peek(*qe));
        dequeue(qe);
    }
}

void pop(struct queue** qe) {
    if (empty(*qe)) {
        printf("Stack is empty\n");
        return;
    }
    dequeue(qe);
}

int top(struct queue** qe) {
    if (empty(*qe)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(*qe);
} */

void main(){
    struct queue* qe;
    initialize(&qe);
    push(&qe,1);
    push(&qe,2);
    push(&qe,3);
    push(&qe,4);
    printf("%d\n",size(qe));
    printf("%d\n",top(&qe));

    pop(&qe);
    printf("%d\n",top(&qe));
}