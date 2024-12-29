#include <stdio.h>

int qq(int a, int b) {
    return a * b;
}
void main() {
    int i = 5, j = 6, c;
    int temp1 = qq(i++, ++j);
    int temp2 = qq(++i, j++);
    c = qq(temp1, temp2);
    printf("%d\n", temp1);
    printf("%d\n", temp2);
    printf("%d\n", c);
    printf("-------------------\n");
    i = 5, j = 6;
    temp1 = qq(++i, j++);
    temp2 = qq(i++, ++j);
    c = qq(temp1, temp2);
    printf("%d\n", temp1);
    printf("%d\n", temp2);
    printf("%d", c);
}

