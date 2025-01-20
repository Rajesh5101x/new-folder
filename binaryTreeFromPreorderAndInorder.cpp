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

struct node* create(int preorder[], int inorder[], int start, int end){
    if(start > end){
        return NULL;
    }
    static int i = 0;
    int curr = preorder[i];
    i++;
    struct node* temp = new node(curr);

    if(start == end){
        return temp;
    }

    int pos = position(inorder,start,end,curr);
    temp->left = create(preorder, inorder, start, pos-1);
    temp->right = create(preorder, inorder, pos+1, end);

    return temp;
}


void inorderDisplay(struct node* root){
    if(root == NULL){
        return;
    }
    inorderDisplay(root->left);
    cout<<root->data<<", ";
    inorderDisplay(root->right);
}


int main(){
    /* int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3}; */

    int preorder[] = {1, 2, 4, 8, 9, 5, 10, 3, 6, 11, 12, 7, 13, 14};
    int inorder[] = {8, 4, 9, 2, 10, 5, 1, 11, 6, 12, 3, 13, 7, 14};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    struct node* root = create(preorder,inorder,0,size-1);
    inorderDisplay(root);

    return 0;
}