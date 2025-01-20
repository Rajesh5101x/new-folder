#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int position(int inorder[], int start, int end, int curr){
    for(int i = start; i <= end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

struct node* create(int postorder[], int inorder[], int start, int end, int &i){
    if(start > end){
        return NULL;
    }

    int curr = postorder[i];
    i--;

    struct node* temp = new node(curr);

    if(start == end){
        return temp;
    }

    int pos = position(inorder,start,end,curr);
    temp->right = create(postorder,inorder,pos+1,end,i);
    temp->left = create(postorder,inorder,start,pos-1,i);

    return temp;
}

void display(struct node* root){
    if(root == NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<", ";
    display(root->right);
}

int main(){
    int postorder[] = {8, 9, 4, 10, 5, 2, 11, 12, 6, 13, 14, 7, 3, 1};
    int inorder[] = {8, 4, 9, 2, 10, 5, 1, 11, 6, 12, 3, 13, 7, 14};

    int size = sizeof(inorder) / sizeof(inorder[0]);
    int i = size - 1;

    struct node* root = create(postorder,inorder,0,size-1,i);
    display(root);

    return 0;
}