#include <stdio.h>

int sum(int a, int b) {
    return (a + b);
}

int sub(int a, int b) {
    return (a - b);
}

int mult(int a, int b) {
    return (a * b);
}

int div(int a, int b) {
    return (a / b);
}

void main() {  
    int a, b;
    char x[1];
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter the operator (+, -, *, /): ");
    scanf("%s", x);

    switch (x[0]) {  
        case '+':
            printf("%d + %d = %d\n", a, b, sum(a, b));
            break;

        case '-':
            printf("%d - %d = %d\n", a, b, sub(a, b));
            break;

        case '*':
            printf("%d * %d = %d\n", a, b, mult(a, b));
            break;

        case '/':
            if (b != 0) {
                printf("%d / %d = %d\n", a, b, div(a, b));
            }
            break;

        default:
            printf("Invalid operator\n");
    } 
}
