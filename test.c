#include<stdio.h>
#include<string.h>

int main() {
    char a[50], b[50], temp[50];
    
    printf("Enter a string: ");
    scanf("%s", a);  // Read the first string into 'a'
    
    strcpy(temp, a);  // Copy 'a' into 'temp' for backup
    
    printf("The lower case: %s\n", strlwr(a));strcpy(a, temp);
    printf("The upper case: %s\n", strupr(a));strcpy(a, temp);
    printf("The length of the string is: %d\n", strlen(a));strcpy(a, temp);
    printf("The reversed string is: %s\n", strrev(a));strcpy(a, temp);

    printf("Enter a second string: ");
    scanf("%s", b);  // Read the second string into 'b'
    
    printf("Comparing two strings: ");
    if (strcmp(a, b) == 0) 
        printf("They are the same\n");
    else 
        printf("They are not the same\n");

    strcpy(a, temp);
    printf("Combining both strings: %s\n", strcat(a, b));

    return 0;
}
