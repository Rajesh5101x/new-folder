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

void subTreeNodes(struct node* root, int k){
    if(root == NULL || k < 0){
        return;
    }
    if(k == 0){
        cout<<root->data<<", ";
        return;
    }
    subTreeNodes(root->left,k-1);
    subTreeNodes(root->right,k-1);
}

int findKNodes(struct node* root, int key, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        subTreeNodes(root,k);
        return 0;
    }

    int left = findKNodes(root->left,key,k);
    if(left != -1){
        if(left + 1 == k){
            cout<<root->data<<", ";
        }else{
            subTreeNodes(root,k-left-2);
        }
        return left+1;
    }

    int right = findKNodes(root->right,key,k);
    if(right != -1){
        if(right + 1 == k){
            cout<<root->data<<", ";
        }else{
            subTreeNodes(root,k-right-2);
        }
        return right+1;
    }
    return -1;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(5);
    root->right = new node(2);

    root->right->left = new node(3);
    root->right->right = new node(4);

    root->left->left = new node(6);

    root->left->left->right = new node(7);

    root->left->left->right->left = new node(8);
    root->left->left->right->right = new node(9);

    findKNodes(root,5,3);
}



