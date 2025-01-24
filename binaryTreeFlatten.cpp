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

void flatten(struct node* root){
    if(root == NULL){
        return;
    }

    if(root->left){
        struct node* tail = root->right;
        root->right = root->left;
        root->left = NULL;
        struct node* temp2 = root->right;
        while(temp2->right != NULL){
            temp2 = temp2->right;
        }
        temp2->right = tail;
    }
    flatten(root->right);
}

void displayTree(node* root, string prefix = "", bool isLeft = true) {
    if (root == NULL) {
        return;
    }

    cout << prefix;

    // Add ASCII-style branch
    if (isLeft) {
        cout << "|-- ";
    } else {
        cout << "\\-- ";
    }

    cout << root->data << endl;

    // Recurse for left and right children
    displayTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
    displayTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    root->left->right->left = new node(10);

    root->right->left->left = new node(11);
    root->right->left->right = new node(12);

    root->right->right->left = new node(13);
    root->right->right->right = new node(14);

    flatten(root);
    displayTree(root);
}