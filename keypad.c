#include<stdio.h>
#include<string.h>

char *key[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void reco(char n[], int i, char x[], int length){
    if(i == length){
        x[i] = '\0';
        printf("%s\n",x);
        return;
    }
    int temp = n[i] - '0';
    for(int k = 0; key[temp][k] != '\0'; k++){
        x[i] = key[temp][k];
        reco(n,i+1,x,length); 
    }
    
}

void main(){
    char n[] = "78";
    char x[2];
    reco(n,0,x,strlen(n));
}

/* void reco(char *x, int index, char *current, int len){
    if(index == len){
        current[index] = '\0';
        printf("%s\n",current);
        return;
    }

    int digit = x[index] - '0';
    char *letter = key[digit];

    for(int i = 0; letter[i] != '\0'; i++){
        current[index] = letter[i];
        reco(x, index + 1, current, len);
    }
}

void main(){
    
    char x[] = "237";
    int size = strlen(x);
    char current[size + 1];

    reco(x,0,current,size);
} */