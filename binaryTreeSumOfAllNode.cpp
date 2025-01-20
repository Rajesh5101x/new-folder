#include<iostream>
#include <vector>
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

void SumOfNode(struct node* root, int &sum){
    if(root == NULL){
        return;
    }
    sum += root->data;
    SumOfNode(root->left, sum);
    SumOfNode(root->right,sum);
}

int recSumOfNode(struct node* root){
    if(root == NULL){
        return 0;
    }
    return recSumOfNode(root->left) + recSumOfNode(root->right) + root->data;
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
    
    int sum = 0;
    SumOfNode(root,sum);
    cout<<sum<<endl;

    cout<<recSumOfNode(root)<<endl;

    return 0;
}