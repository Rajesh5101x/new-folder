#include<iostream>
#include<queue>
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

int replaceNodeWithSum(struct node* root){
    if(root == NULL){
        return 0;
    }

    root->data = replaceNodeWithSum(root->left) + replaceNodeWithSum(root->right) + root->data;
    return root->data;
}

void displayBinaryTree(struct node* root){
    queue<struct node*> qe;
    qe.push(root);
    qe.push(NULL);

    while(!qe.empty()){
        struct node* temp = qe.front();
        qe.pop();
        if(temp != NULL){
            cout<<temp->data<<", ";
            if(temp->left){
                qe.push(temp->left);
            }
            if(temp->right){
                qe.push(temp->right);
            }
        }else if(!qe.empty()){
            qe.push(NULL);
        }
    }
    cout<<endl;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<replaceNodeWithSum(root)<<endl;
    displayBinaryTree(root);

    return 0;
}