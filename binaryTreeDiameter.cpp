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

calcHeight(struct node* root){
    if(root == NULL){
        return 0;
    }
    return max(calcHeight(root->left), calcHeight(root->right))+1;
}

int calcDiameter(struct node* root){
    if(root == NULL){
        return 0;
    }

    int currDiameter = calcHeight(root->left) + calcHeight(root->right) + 1;
    int diameter = max(calcDiameter(root->left), calcDiameter(root->right));
    
    return max(currDiameter, diameter);
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

    cout<<calcDiameter(root)<<endl;
    
    return 0;
}