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

int maxSumPath(struct node* root, int &maxSum){
    if(root == NULL){
        return 0;
    }
    int left = max(0, maxSumPath(root->left, maxSum));
    int right = max(0, maxSumPath(root->right, maxSum));
    maxSum = max(maxSum, left + right + root->data);

    return root->data + max(left, right);
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);

    root->right = new node(3);
    root->right->right = new node(5);

    int maxSum = INT_MIN;
    maxSumPath(root, maxSum);
    cout << "Maximum Path Sum: " << maxSum << endl;
}