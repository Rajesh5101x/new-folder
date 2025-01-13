#include<stdio.h>
#include<stdlib.h>
#define n 100

struct stack{
    int *arr;
    int top;
};

void initialize(struct stack* st){
    st->arr = (int *)malloc(n * sizeof(int));
    if(!st->arr){
        printf("Memory Allocation Failed!\n");
        return;
    }
    st->top = -1;
}

void push(struct stack* st, int val){
    if(st->top == n-1){
        printf("Stack is full\n");
        return;
    }
    st->arr[++(st->top)] = val;
}

void pop(struct stack* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    st->top--;
}

void top(struct stack* st){
    if(st->top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n",st->arr[st->top]);
}

void empty(struct stack* st){
    if(st->top == -1){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
}

void main(){
    struct stack st;
    initialize(&st);
    empty(&st);
    pop(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    push(&st,6);
    top(&st);
    pop(&st);
    top(&st);
}