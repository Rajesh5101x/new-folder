#include <stdio.h>
#include <stdlib.h>
#define n 100

struct queue {
    int *arr;
    int front;
    int back;
};

void initialization(struct queue **qe) {
    *qe = (struct queue *)malloc(sizeof(struct queue));
    if (!(*qe)) {
        printf("Queue structure allocation failed\n");
        return;
    }

    (*qe)->arr = (int *)malloc(n * sizeof(int));
    if (!(*qe)->arr) {
        printf("Queue array allocation failed\n");
        free(*qe);
        *qe = NULL;
        return;
    }

    (*qe)->front = -1;
    (*qe)->back = -1;
}

void enqueue(struct queue *qe, int val) {
    if (qe->back == n - 1) {
        printf("Queue is full\n");
        return;
    }
    if (qe->front == -1) {
        qe->front = 0; 
    }
    qe->arr[++(qe->back)] = val;
}

void dequeue(struct queue *qe) {
    if (qe->front == -1 || qe->front > qe->back) {
        printf("Queue is empty\n");
        return;
    }
    qe->front++;
}

void peek(struct queue *qe) {
    if (qe->front == -1 || qe->front > qe->back) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d\n", qe->arr[qe->front]);
}

int empty(struct queue *qe) {
    if (qe->front == -1 || qe->front > qe->back) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct queue *qe;
    initialization(&qe);

    if (!qe) {
        return -1;
    }

    enqueue(qe, 1);
    enqueue(qe, 2);
    enqueue(qe, 3);
    enqueue(qe, 4);
    peek(qe);
    dequeue(qe);
    peek(qe);

    free(qe->arr);
    free(qe);

    return 0;
}
