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

struct node* insertVal(struct node* root, int val){
    if(root == NULL){
        return new node(val);
    }

    if(val < root->data){
        root->left = insertVal(root->left, val);
    }else{
        root->right = insertVal(root->right, val);
    }

    return root;
}

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

int main(){
    struct node* root = NULL;
    root = insertVal(root, 5);
    insertVal(root, 1);
    insertVal(root, 3);
    insertVal(root, 4);
    insertVal(root, 2);
    insertVal(root, 7);

    inorder(root);

    return 0;
}