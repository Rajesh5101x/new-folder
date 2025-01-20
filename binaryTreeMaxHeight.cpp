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

int calcMaxHeight(struct node* root){
    if(root == NULL){
        return 0;
    }
    
    return max(calcMaxHeight(root->left),calcMaxHeight(root->right)) + 1 ;
}

int main(){
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    
    root->right->left = new node(6);
    
    root->left->left->left = new node(7);
    root->left->left->right = new node(8);
    
    cout<<calcMaxHeight(root)<<endl;

    return 0;
}