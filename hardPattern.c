#include<stdio.h>

void main(){
    int n = 6;
    int x = 1;
    int flag = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i ; j++){
            printf(" ");
        }
        for(int k = 0; k < (n-i)+1; k++){
            if(flag == 0){
                if(x > 8){
                    printf("9 ");
                    x = 0;
                    flag++;
                }else{
                    printf("%d ",x++);
                }
            }else{
                printf("%d ",x);
                if(x == 9){
                    x = 0;
                }else{
                    x = 9;
                }
            }
        }
        printf("\n");
    }
    flag = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= (n-i)+1 ; j++){
            printf(" ");
        }
        for(int k = 0; k < i; k++){
            if(i == 5 && k == 3){
                flag++;
                x = 8;
            }
            if(flag == 0){
                printf("%d ",x);
                if(x == 9){
                    x = 0;
                }else{
                    x = 9;
                }
            }else{
                printf("%d ",x--);
            }
        }
        printf("\n");
    }
}