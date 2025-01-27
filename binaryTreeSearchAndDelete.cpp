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

struct node* findMin(struct node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key){
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }else if(root->left == NULL){
            struct node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            struct node* temp = root->left;
            delete root;
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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
    struct node* root = new node(4);

    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);

    root->right = new node(5);
    root->right->right = new node(6);

    deleteNode(root,5);
    inorder(root);
}